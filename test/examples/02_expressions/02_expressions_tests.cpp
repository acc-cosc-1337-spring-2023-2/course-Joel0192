#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp f
#include "catch.hpp"
#include "constants.h"

TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}

TEST_CASE("Verify get area of cirlce")
{
	REQUIRE(get_area_of_circle(10) ==314.159);
}