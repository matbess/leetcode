#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Solution.h"

using namespace std;
using namespace leetcode;

TEST_CASE("threeSumClosest", "[threeSumClosest]")
{
    Solution solution;

    SECTION("Simple sets with sum != target")
    {
        REQUIRE(solution.threeSumClosest({-1,2,1,-4}, 1) == 2);
        REQUIRE(solution.threeSumClosest({-1,2,1,-4}, -8) == -4);
        REQUIRE(solution.threeSumClosest({-1,2,1,-4}, 8) == 2);
    }

    SECTION("Simple sets with sum == target")
    {
        REQUIRE(solution.threeSumClosest({5,-5,1,2,3,-1}, 0) == 0);
        REQUIRE(solution.threeSumClosest({5,-5,1,2,3,-1}, 8) == 8);
        REQUIRE(solution.threeSumClosest({5,-5,1,2,3,-1}, 10) == 10);
    }

    SECTION("Minimum set size (3)")
    {
        REQUIRE(solution.threeSumClosest({1000,1000,1000}, -3) == 3000);
        REQUIRE(solution.threeSumClosest({1000,1000,1000}, -1000) == 3000);
        REQUIRE(solution.threeSumClosest({1000,1000,1000}, 3000) == 3000);
    }

    SECTION("Min/max target values")
    {
        REQUIRE(solution.threeSumClosest({-1,2,1,-4}, 10000) == 2);   // -1,1,2
        REQUIRE(solution.threeSumClosest({-1,2,1,-4}, -10000) == -4); // -4,-1,1
        REQUIRE(solution.threeSumClosest({-10000,10000,2,1,-4}, 2) == 2);
        REQUIRE(solution.threeSumClosest({-10000,10000,2,1,-4}, 10000) == 9998);
    }

    SECTION("Large set")
    {
        vector<int> v = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
        REQUIRE(solution.threeSumClosest(v, -10) == 3);
        REQUIRE(solution.threeSumClosest(v, 256) == 256);
        REQUIRE(solution.threeSumClosest(v, 270) == 270);
        REQUIRE(solution.threeSumClosest(v, 20000) == 294);
    }
}

