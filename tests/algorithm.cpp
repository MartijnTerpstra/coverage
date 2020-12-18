#include <algorithm.hpp>

#include <gtest/gtest.h>

TEST(Saturate, OnlyGoodValues) {
    ASSERT_EQ(mtmath::saturate(0.5f), 0.5f);
}

TEST(Saturate, NegativeValuesShouldBeZero) {
    ASSERT_EQ(mtmath::saturate(-0.5f), 0.f);
}