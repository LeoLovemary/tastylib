#include "gtest/gtest.h"
#include "tastylib/LCS.h"
#include <string>

using namespace tastylib;
using std::string;

TEST(LCS, Basic) {
    ASSERT_EQ((std::size_t)0, lcs("", ""));
    ASSERT_EQ((std::size_t)2, lcs("aa", "aa"));
    ASSERT_EQ((std::size_t)7, lcs("aa123XXXXabc", "abc123abc"));
    ASSERT_EQ((std::size_t)4, lcs("3256abcde", "1X2XcXdXe"));
}

