#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "val_ref.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test value, ref, n const ref parameter")
{
	auto num = 10;
	auto num1 = 10;
	auto num2 = 10;

	val_ref_params(num, num1, num2);
	REQUIRE( num == 10);
	REQUIRE(num1 == 10);
	REQUIRE(num2 = 10);

}

