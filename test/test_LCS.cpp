#include "gtest/gtest.h"
#include "tastylib/LCS.h"
#include "tastylib/util/convert.h"
#include <string>

using namespace tastylib;
using std::string;

TEST(LCS, Basic) {
    ASSERT_EQ(0, lcs("", ""));
    ASSERT_EQ(2, lcs("aa", "aa"));
    ASSERT_EQ(7, lcs("aa123XXXXabc", "abc123abc"));
}

