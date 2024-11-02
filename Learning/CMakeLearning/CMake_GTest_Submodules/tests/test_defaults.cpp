/**
 * tests/test_defaults.cpp
 */

#include "person.hpp"
#include "gtest/gtest.h"

namespace gtestbox {
    namespace tests {
        namespace test_hello {
            TEST(TestDefaults, BasicAssertions) {
                gtestbox::person::Person p;
                EXPECT_STREQ(p.name.c_str(), "unknown");
                EXPECT_EQ(p.age, 0);
            }

            TEST(TestDefaults, BasicAssertions_1) {
                gtestbox::person::Person p;
                std::string msg = "Tung";
                p.sayHello(msg);
                EXPECT_EQ(p.age, 0);
            }

            TEST(TestDefaults, BasicAssertions_2) {
                gtestbox::person::Person p;
                std::string msg = "T";
                p.sayHello(msg);
                EXPECT_EQ(p.age, 0);
            }

            TEST(TestDefaults, BasicAssertions_3) {
                gtestbox::person::Person p;
                std::string msg = "Tung123";
                p.sayHello(msg);
                EXPECT_EQ(p.age, 0);
            }
        }
    }
}

int main(int nArgs, char** vArgs) {
    ::testing::InitGoogleTest(&nArgs, vArgs);
    return RUN_ALL_TESTS();
}