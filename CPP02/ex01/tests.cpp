#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Fixed.hpp"
#include <sstream>

TEST_CASE("values that land exactly on the grid")
{
	CHECK(Fixed(0).toFloat() == 0.0f);
	CHECK(Fixed(10).toFloat() == 10.0f);
	CHECK(Fixed(0.5f).toFloat() == 0.5f);
	CHECK(Fixed(0.25f).toFloat() == 0.25f);
}

TEST_CASE("values that lose precision")
{
	CHECK(Fixed(42.42f).toFloat() == doctest::Approx(42.42f).epsilon(0.004));
	CHECK(Fixed(0.1f).toFloat() == doctest::Approx(0.1f).epsilon(0.004));
}

TEST_CASE("internal raw value is as expected")
{
	CHECK(Fixed(1).getRawBits() == 256);
	CHECK(Fixed(10).getRawBits() == 2560);
	CHECK(Fixed(0.5f).getRawBits() == 128);
	CHECK(Fixed(42.42f).getRawBits() == 10860);
}

TEST_CASE("toInt truncates, does not round")
{
	CHECK(Fixed(42.42f).toInt() == 42);
	CHECK(Fixed(42.99f).toInt() == 42);
}

TEST_CASE("negative numbers")
{
	CHECK(Fixed(-10).getRawBits() == -2560);
	CHECK(Fixed(-0.5f).getRawBits() == -128);
	CHECK(Fixed(-42.42f).toInt() == -42);
}

TEST_CASE("int round trip is lossless")
{
	for (int i = -100; i <= 100; i++)
		CHECK(Fixed(i).toInt() == i);
}

TEST_CASE("epsilon: smallest representable value")
{
	Fixed eps;
	eps.setRawBits(1);
	CHECK(eps.toFloat() == 0.00390625f);
	CHECK(eps.toInt() == 0);
}

TEST_CASE("operator<< prints the floating point representation")
{
	std::ostringstream oss;
	oss << Fixed(42.42f);
	CHECK(oss.str() == "42.4219");
}

TEST_CASE("range limits saturate instead of overflowing")
{
	CHECK(Fixed(8388607).toInt() == 8388607);
	CHECK(Fixed(8388608).getRawBits() == 2147483647);
	CHECK(Fixed(100000000).getRawBits() == 2147483647);
	CHECK(Fixed(-8388609).getRawBits() == -2147483648);
}

TEST_CASE("degenerate float inputs are handled")
{
	CHECK(Fixed(0.0f / 0.0f).getRawBits() == 0);
	CHECK(Fixed(1.0f / 0.0f).getRawBits() == 2147483647);
	CHECK(Fixed(-1.0f / 0.0f).getRawBits() == -2147483648);
	CHECK(Fixed(1e20f).getRawBits() == 2147483647);
	CHECK(Fixed(-1e20f).getRawBits() == -2147483648);
}

TEST_CASE("float constructor saturates at the int boundary")
{
	CHECK(Fixed(8388607.0f).getRawBits() == 2147483392);
	CHECK(Fixed(8388608.0f).getRawBits() == 2147483647);
	CHECK(Fixed(8388607.9f).getRawBits() == 2147483647);
	CHECK(Fixed(-8388608.0f).getRawBits() == -2147483647 - 1);
	CHECK(Fixed(-8388609.0f).getRawBits() == -2147483647 - 1);
}
