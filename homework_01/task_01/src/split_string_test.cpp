#include <gtest/gtest.h>

#include "utils.hpp"

TEST(SplitStringTest, Simple) {
  ASSERT_EQ(SplitString(""), std::vector<std::string>{});
  ASSERT_EQ(SplitString("aaa"), std::vector<std::string>{"aaa"});
  ASSERT_EQ(SplitString("aaa aaa"), (std::vector<std::string>{"aaa", "aaa"}));
  ASSERT_EQ(SplitString("aaa aaa "), (std::vector<std::string>{"aaa", "aaa"}));
  ASSERT_EQ(SplitString(" "), std::vector<std::string>{});
  ASSERT_EQ(SplitString("??? ??"), (std::vector<std::string>{"???", "??"}));
  ASSERT_EQ(SplitString("a\na\ta a"),
            (std::vector<std::string>{"a\na", "a", "a"}));
  ASSERT_EQ(SplitString("a (a a)"), (std::vector<std::string>{"a", "(a a)"}));
  ASSERT_EQ(SplitString("a (a a) b (asd as)  "),
            (std::vector<std::string>{"a", "(a a)", "b", "(asd as)"}));
}
