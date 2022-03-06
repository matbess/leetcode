#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Solution.h"

using namespace std;
using namespace leetcode;


TEST_CASE("champagneTower", "[champagneTower]")
{
    SECTION("Validate result")
    {
        Solution s;
        REQUIRE(s.champagneTower(1, 1, 1) == 0.0);
        REQUIRE(s.champagneTower(2, 1, 1) == 0.5);
        REQUIRE(s.champagneTower(100000009, 33, 17) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 16, 16) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 27, 27) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 28, 28) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 30, 29) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 30, 30) == 0.0);
        REQUIRE(s.champagneTower(1000000000, 36, 25) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 36, 34) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 36, 35) == 0.0);
        REQUIRE(s.champagneTower(1000000000, 56, 25) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 67, 25) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 67, 55) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 67, 56) == 1.0);
        REQUIRE(s.champagneTower(1000000000, 67, 57) == 0.0);
        REQUIRE(s.champagneTower(1000000000, 90, 25) == 1.0);
    }
}

