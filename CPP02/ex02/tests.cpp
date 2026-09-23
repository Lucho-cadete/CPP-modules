//c++ -std=c++11 tests.cpp Fixed.cpp -o tests && ./tests

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

TEST_CASE("pre-increment returns the new value")
{
	Fixed a;
	CHECK((++a).getRawBits() == 1);
	CHECK(a.getRawBits() == 1);
}

TEST_CASE("post-increment returns the old value")
{
	Fixed a;
	CHECK((a++).getRawBits() == 0);
	CHECK(a.getRawBits() == 1);
}

TEST_CASE("pre-decrement returns the new value")
{
	Fixed a;
	CHECK((--a).getRawBits() == -1);
	CHECK(a.getRawBits() == -1);
}

TEST_CASE("post-decrement returns the old value")
{
	Fixed a;
	CHECK((a--).getRawBits() == 0);
	CHECK(a.getRawBits() == -1);
}

TEST_CASE("increment adds epsilon")
{
	Fixed a;
	a++;
	CHECK(a.toFloat() == 0.00390625f);
}

TEST_CASE("min and max")
{
	Fixed a(5);
	Fixed b(3);

	CHECK(Fixed::max(a, b).toInt() == 5);
	CHECK(Fixed::min(a, b).toInt() == 3);
	CHECK(Fixed::max(b, a).toInt() == 5);
	CHECK(Fixed::min(b, a).toInt() == 3);
}

TEST_CASE("min and max with const objects")
{
	Fixed const a(5);
	Fixed const b(3);

	CHECK(Fixed::max(a, b).toInt() == 5);
	CHECK(Fixed::min(a, b).toInt() == 3);
}

TEST_CASE("max returns a reference to the original")
{
	Fixed a(5);
	Fixed b(3);

	Fixed::max(a, b) = Fixed(100);
	CHECK(a.toInt() == 100);
	CHECK(b.toInt() == 3);
}