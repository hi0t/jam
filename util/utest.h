#pragma once

#include "utest_internal.h"

#define TEST(name)                                                                                                 \
    static_assert(sizeof(#name) > 1, "test name must not be empty");                                               \
    void test_##name();                                                                                            \
    const bool test_##name##_registered = Internal::UnitTest::getInstance().registerTest({ #name, &test_##name }); \
    void test_##name()

#define EXPECT_EQ(...) \
    Internal::compare(__VA_ARGS__, __FILE__, __LINE__)

#define ASSERT_EQ(...)                                       \
    if (!Internal::compare(__VA_ARGS__, __FILE__, __LINE__)) \
    [] { asm("int3"); }()
