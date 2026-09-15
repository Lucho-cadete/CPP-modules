#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int suma(int a, int b)
{
    return a + b;
}

TEST_CASE("la suma funciona")
{
    CHECK(suma(2, 3) == 5);
    CHECK(suma(-1, 1) == 0);
    CHECK(suma(0, 0) == 0);
}
