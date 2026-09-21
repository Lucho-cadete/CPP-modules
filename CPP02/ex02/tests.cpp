#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Fixed.hpp"
#include <sstream>

TEST_CASE("comparison operators")
{
	Fixed a(5);
	Fixed b(3);
	Fixed c(5);

	CHECK(a > b);
	CHECK_FALSE(b > a);
	CHECK(b < a);
	CHECK_FALSE(a < b);

	CHECK(a >= b);
	CHECK(a >= c);
	CHECK_FALSE(b >= a);

	CHECK(b <= a);
	CHECK(a <= c);
	CHECK_FALSE(a <= b);

	CHECK(a == c);
	CHECK_FALSE(a == b);

	CHECK(a != b);
	CHECK_FALSE(a != c);
}

TEST_CASE("comparisons with decimals and negatives")
{
	CHECK(Fixed(0.5f) > Fixed(0.25f));
	CHECK(Fixed(-1) < Fixed(0));
	CHECK(Fixed(-0.5f) > Fixed(-1));
	CHECK(Fixed(42.42f) == Fixed(42.42f));
}

TEST_CASE("addition and subtraction")
{
	CHECK((Fixed(5) + Fixed(3)).toInt() == 8);
	CHECK((Fixed(5) - Fixed(3)).toInt() == 2);
	CHECK((Fixed(3) - Fixed(5)).toInt() == -2);
	CHECK((Fixed(0.5f) + Fixed(0.25f)).toFloat() == 0.75f);
	CHECK((Fixed(1.5f) - Fixed(0.5f)).toFloat() == 1.0f);
}

TEST_CASE("multiplication and division")
{
	CHECK((Fixed(2) * Fixed(3)).toInt() == 6);
	CHECK((Fixed(6) / Fixed(3)).toInt() == 2);
	CHECK((Fixed(3) / Fixed(6)).toFloat() == 0.5f);
	CHECK((Fixed(-2) * Fixed(3)).toInt() == -6);
	CHECK((Fixed(0.5f) * Fixed(0.5f)).toFloat() == 0.25f);
}

TEST_CASE("subject example: 5.05 * 2")
{
	Fixed b(Fixed(5.05f) * Fixed(2));
	CHECK(b.getRawBits() == 2586);
}

TEST_CASE("division by zero does not crash")
{
	CHECK((Fixed(5) / Fixed(0)).getRawBits() == 2147483647);
	CHECK((Fixed(-5) / Fixed(0)).getRawBits() == -2147483648);
	CHECK((Fixed(0) / Fixed(0)).getRawBits() == 0);
}