#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "problem_a.hpp"

TEST_CASE("Factorials are computed with case 1", "[case_1]")
{
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
}

TEST_CASE("Factorials are computed with case 2", "[case_2]")
{
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(10) == 3628800);
}