#include <algorithm.h>

#if 0
#include <gtest/gtest.h>

TEST(Saturate, OnlyGoodValues)
{
	ASSERT_EQ(mtmath::saturate(0.5f), 0.5f);
}

TEST(Saturate, NegativeValuesShouldBeZero)
{
	ASSERT_EQ(mtmath::saturate(-0.5f), 0.f);
}

TEST(Saturate, MaxValueShouleBeOne)
{
	ASSERT_EQ(mtmath::saturate(100), 1.f);
}

#else

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Saturate: OnlyGoodValues", "[Algo]")
{
	REQUIRE(mtmath::saturate(0.5f) == 0.5f);
}

TEST_CASE("Saturate: NegativeValuesShouldBeZero", "[Algo]")
{
	REQUIRE(mtmath::saturate(-0.5f) == 0.f);
}

TEST_CASE("Saturate: MaxValueShouleBeOne", "[Algo]")
{
	REQUIRE(mtmath::saturate(100) == 1.f);
}

TEST_CASE("Clamp: OnlyGoodValues", "[Algo]")
{
	REQUIRE(mtmath::clamp(0.5f, 0, 1) == 0.5f);
}

TEST_CASE("Clamp: NegativeValuesShouldBeZero", "[Algo]")
{
	REQUIRE(mtmath::clamp(-0.5f, 0, 1) == 0.f);
}

TEST_CASE("Clamp: MaxValueShouleBeOne", "[Algo]")
{
	REQUIRE(mtmath::clamp(100, 0, 1) == 1.f);
}


#endif