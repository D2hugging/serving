
#include "core/servable_data.h"

#include <string>

#include <gtest/gtest.h>


namespace serving {
namespace {

TEST(ServableDataTest, NoError) {
  ServableId id = {"name", 42};
  ServableData<std::string> data(id, "yo");
  EXPECT_EQ(id, data.id());
  // EXPECT_EQ(Status::OK(), data.status());
  EXPECT_EQ("yo", data.DataOrDie());
  EXPECT_EQ("yo", data.ConsumeDataOrDie());
}

TEST(ServableDataTest, StaticCreateNoError) {
  ServableId id = {"name", 42};
  auto data = CreateServableData(id, "yo");
  EXPECT_EQ(id, data.id());
  // EXPECT_EQ(Status::OK(), data.status());
  EXPECT_EQ("yo", data.DataOrDie());
  EXPECT_EQ("yo", data.ConsumeDataOrDie());
}

// TEST(ServableDataTest, Error) {
//   ServableId id = {"name", 42};
//   ServableData<std::string> data(id, Status::OK());
//   EXPECT_EQ(id, data.id());
//   // EXPECT_EQ(Status::OK(), data.status());
// }

}  // namespace
}  // namespace serving
