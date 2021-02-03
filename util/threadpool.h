#ifndef _SERVING_UTIL_THREADPOOL_H_
#define _SERVING_UTIL_THREADPOOL_H_

#include <vector>
#include <queue>
#include <thread>
#include <functional>

#include "absl/synchronization/mutex.h"
#include "absl/base/thread_annotations.h"

#include "util/micros.h"

namespace serving {

class ThreadPool {
 public:
  explicit ThreadPool(int num_threads) {
      for (size_t i = 0; i < num_threads; ++i) {
          threads_.push_back(std::thread(&ThreadPool::Loop, this));
      }
  }

  ~ThreadPool() {
      {
          absl::MutexLock l(&mtx_);
          for (size_t i = 0; i < threads_.size(); ++i) {
              queue_.push(nullptr);
          }
      }

      for (auto &t : threads_) {
          if (t.joinable()) {
              t.join();
          }
      }
  }

  void Schedule(std::function<void()> fn) {
      assert(fn != nullptr);
      {
        absl::MutexLock l(&mtx_);
        queue_.push(std::move(fn));
      }
  }

  void Cancel() {
      for (auto &t : threads_) {
          if (t.joinable()) {
              auto tid = t.native_handle();
              if (tid) {
                  ::pthread_cancel(tid);
              }
          }
      }
  }

  std::size_t NumWorkers() const {
      return threads_.size();
  }

  DISALLOW_COPY_AND_ASSIGN(ThreadPool);

 private:
  bool Available() EXCLUSIVE_LOCKS_REQUIRED(mtx_) {
    //   absl::MutexLock l(&mtx_);
      return !queue_.empty();
  }

  void Loop() {
      while (true) {
          std::function<void()> fn;
          {
              absl::MutexLock l(&mtx_);
              mtx_.Await(absl::Condition(this, &ThreadPool::Available));
              fn = std::move(queue_.front());
              queue_.pop();
          }
          if (fn == nullptr) {
              break;
          }
          fn();
      }
  }

 private:
  absl::Mutex mtx_;
  std::queue<std::function<void()>> queue_ GUARDED_BY(mtx_);
  std::vector<std::thread> threads_;
};

}  // namespace serving

#endif