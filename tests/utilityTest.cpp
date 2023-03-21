#include <gtest/gtest.h>

#include "Monitor.h"
#include "utilFunctions.h"

namespace {
    TEST(toLower, first) {
        std::string str = "Aaaa";
        toLower(str);
        EXPECT_EQ(str, "aaaa");
    }

    TEST(toLower, last) {
        std::string str = "AatB";
        toLower(str);
        EXPECT_EQ(str, "aatb");
    }

    TEST(toLower, t1) {
        std::string str = "AAbbBBfds AWAD Wa";
        toLower(str);
        EXPECT_EQ(str, "aabbbbfds awad wa");
    }

    TEST(toLower, t2) {
        std::string str = "QWE123";
        toLower(str);
        EXPECT_EQ(str, "qwe123");
    }

    TEST(toLower, t3) {
        std::string str = "Q";
        toLower(str);
        EXPECT_EQ(str, "q");
    }

    TEST(isWhitespace, t1) {
        EXPECT_EQ(isWhitespace(' '), true);
    }

    TEST(isWhitespace, t2) {
        EXPECT_EQ(isWhitespace('\t'), true);
    }

    TEST(isWhitespace, t3) {
        EXPECT_EQ(isWhitespace('a'), false);
    }
}
