#include "util/threadpool.h"

#include <gtest/gtest.h>

namespace serving {
namespace {

TEST(ThreadPoolTest, NoError) {

  ThreadPool tp(4);
  tp.Schedule([](){;});
  EXPECT_EQ(tp.NumWorkers(), 4);
}

}  // namespace
}  // namespace serving

