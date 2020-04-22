#pragma once

#include "utest_internal.h"

#define TEST(name)                                                                                       \
static_assert(sizeof(#name) > 1, "test name must not be empty");                                         \
void test_##name();                                                                                      \
const bool test_##name##_registered = internal::UnitTest::GetInstance().Register({#name, &test_##name}); \
void test_##name()

#define EXPECT_EQ(...)                                   \
internal::Compare(__VA_ARGS__, __FILE__, __LINE__)

#define ASSERT_EQ(...)                                   \
if (!internal::Compare(__VA_ARGS__, __FILE__, __LINE__)) \
    []{ asm("int3"); }()
