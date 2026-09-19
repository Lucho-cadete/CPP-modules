#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Fixed.hpp"
#include <sstream>

TEST_CASE("valores que caen exactos en la rejilla")
{
	CHECK(Fixed(0).toFloat() == 0.0f);
	CHECK(Fixed(10).toFloat() == 10.0f);
	CHECK(Fixed(0.5f).toFloat() == 0.5f);
	CHECK(Fixed(0.25f).toFloat() == 0.25f);
}

TEST_CASE("valores con perdida de precision")
{
	CHECK(Fixed(42.42f).toFloat() == doctest::Approx(42.42f).epsilon(0.004));
	CHECK(Fixed(0.1f).toFloat() == doctest::Approx(0.1f).epsilon(0.004));
}

TEST_CASE("el valor interno es el esperado")
{
	CHECK(Fixed(1).getRawBits() == 256);
	CHECK(Fixed(10).getRawBits() == 2560);
	CHECK(Fixed(0.5f).getRawBits() == 128);
	CHECK(Fixed(42.42f).getRawBits() == 10860);
}

TEST_CASE("toInt trunca, no redondea")
{
	CHECK(Fixed(42.42f).toInt() == 42);
	CHECK(Fixed(42.99f).toInt() == 42);
}

TEST_CASE("numeros negativos")
{
	CHECK(Fixed(-10).getRawBits() == -2560);
	CHECK(Fixed(-0.5f).getRawBits() == -128);
	CHECK(Fixed(-42.42f).toInt() == -42);
}

TEST_CASE("ida y vuelta con enteros es exacta")
{
	for (int i = -100; i <= 100; i++)
		CHECK(Fixed(i).toInt() == i);
}

TEST_CASE("epsilon: el valor mas pequeno representable")
{
	Fixed eps;
	eps.setRawBits(1);
	CHECK(eps.toFloat() == 0.00390625f);
	CHECK(eps.toInt() == 0);
}

TEST_CASE("operator<< imprime la representacion en coma flotante")
{
	std::ostringstream oss;
	oss << Fixed(42.42f);
	CHECK(oss.str() == "42.4219");
}

TEST_CASE("comportamiento en casos degenerados")
{
	std::cout << "--- desbordamiento ---" << std::endl;
	std::cout << "8388607 -> " << Fixed(8388607).toInt() << std::endl;
	std::cout << "8388608 -> " << Fixed(8388608).toInt() << std::endl;
	std::cout << "100000000 -> " << Fixed(100000000).toInt() << std::endl;

	std::cout << "--- inf y nan ---" << std::endl;
	std::cout << "inf -> " << Fixed(1.0f / 0.0f).getRawBits() << std::endl;
	std::cout << "-inf -> " << Fixed(-1.0f / 0.0f).getRawBits() << std::endl;
	std::cout << "nan -> " << Fixed(0.0f / 0.0f).getRawBits() << std::endl;

	std::cout << "--- floats enormes ---" << std::endl;
	std::cout << "1e20 -> " << Fixed(1e20f).getRawBits() << std::endl;
	std::cout << "-1e20 -> " << Fixed(-1e20f).getRawBits() << std::endl;
}
