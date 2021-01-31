#ifndef _SERVING_SERVABLE_DATA_H_
#define _SERVING_SERVABLE_DATA_H_

#include <algorithm>
#include <type_traits>

#include "util/status.h"
// #include "tensorflow/core/platform/logging.h"
#include "core/servable_id.h"

#define CHECK(conditon)   \
    if (!conditon) {      \
      exit(EXIT_FAILURE); \
    }                     \
  

namespace serving {

// A servable id, and associated with it either an error, or data of type T.
// REQUIRES: T is move-constructible. T cannot be Status.
template <typename T>
class ServableData {
  static_assert(std::is_move_constructible<T>::value,
                "ServableData<T> requires that T is move-constructible.");
  static_assert(
      !std::is_same<T, Status>::value,
      "ServableData<T> requires that T not be tensorflow::serving::Status.");

 public:
  // Creates a ServableData<T> with an okay status.
  ServableData(const ServableId& id, T data);

  // Creates a ServableData<T> with an error status. Uses a default-constructed
  // data value. CHECK-fails if 'error.ok()'.
  ServableData(const ServableId& id, const Status& error);

  // Copy constructor.
  ServableData(const ServableData& other) = default;

  // Assignment operator.
  ServableData& operator=(const ServableData& other) = default;

  // Move constructor.
  ServableData(ServableData&& other) = default;

  const ServableId& id() const { return id_; }

  const Status& status() const { return status_; }

  // Returns a reference to the data, or CHECK-fails if !this->ok().
  const T& DataOrDie() const;
  T& DataOrDie();

  // Moves the data out of this object and returns it, or CHECK-fails if
  // !this->ok().
  T ConsumeDataOrDie();

 private:
  ServableData() = delete;

  const ServableId id_;
  const Status status_;
  T data_;
};

// Helper static method to create a ServableData object. Caller may skip
// specifying the template argument because of ADL (argument dependent lookup)
// unlike the ctor.
template <typename T>
ServableData<T> CreateServableData(const ServableId& id, T data);

//////////
// Implementation details follow. API users need not read.

template <typename T>
ServableData<T>::ServableData(const ServableId& id, T data)
    : id_(id), status_(Status::OK()), data_(std::move(data)) {}

template <typename T>
ServableData<T>::ServableData(const ServableId& id, const Status& error)
    : id_(id), status_(error) {
  CHECK(!error.ok());
}

template <typename T>
const T& ServableData<T>::DataOrDie() const {
  CHECK(status_.ok());
  return data_;
}

template <typename T>
T& ServableData<T>::DataOrDie() {
  CHECK(status_.ok());
  return data_;
}

template <typename T>
T ServableData<T>::ConsumeDataOrDie() {
  return std::move(DataOrDie());
}

template <typename T>
ServableData<T> CreateServableData(const ServableId& id, T data) {
  return ServableData<T>(id, std::move(data));
}

}  // namespace serving

#endif  // TENSORFLOW_SERVING_CORE_SERVABLE_DATA_H_
