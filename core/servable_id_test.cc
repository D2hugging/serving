#include <gtest/gtest.h>
#include "core/servable_id.h"

namespace serving {
namespace {
TEST(ServableIdTest, Equals) {
  EXPECT_TRUE((ServableId{"a", 1} == ServableId{"a", 1}));

  EXPECT_FALSE((ServableId{"b", 2} == ServableId{"a", 2}));
  EXPECT_FALSE((ServableId{"b", 1} == ServableId{"b", 2}));
}

TEST(ServableIdTest, NotEquals) {
  EXPECT_FALSE((ServableId{"a", 1} != ServableId{"a", 1}));

  EXPECT_TRUE((ServableId{"b", 2} != ServableId{"a", 2}));
  EXPECT_TRUE((ServableId{"b", 1} != ServableId{"b", 2}));
}

TEST(ServableIdTest, LessThan) {
  EXPECT_TRUE((ServableId{"a", 1} < ServableId{"b", 1}));
  EXPECT_TRUE((ServableId{"b", 1} < ServableId{"b", 2}));
  EXPECT_TRUE((ServableId{"a", 1} < ServableId{"b", 2}));

  EXPECT_FALSE((ServableId{"a", 1} < ServableId{"a", 1}));

  EXPECT_FALSE((ServableId{"b", 1} < ServableId{"a", 1}));
  EXPECT_FALSE((ServableId{"b", 2} < ServableId{"b", 1}));
  EXPECT_FALSE((ServableId{"b", 2} < ServableId{"a", 1}));
}

}  // namespace
}  // namespace serving