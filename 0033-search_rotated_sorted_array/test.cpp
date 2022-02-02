#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"
#include "solution.h"

using namespace std;
using namespace leetcode;

class TestSolution : public Solution
{
public:
    // expose protected methods for tests
    int findPivot(const vector<int>& nums) { return Solution::findPivot(nums); }
};

TEST_CASE("findPivot", "[findPivot]")
{
    TestSolution solution;

    SECTION("array size 7 with pivot")
    {
        REQUIRE(solution.findPivot({7,0,1,2,3,4,5}) == 1);
        REQUIRE(solution.findPivot({7,8,0,1,2,3,4}) == 2);
        REQUIRE(solution.findPivot({7,8,9,1,2,3,4}) == 3);
        REQUIRE(solution.findPivot({4,5,6,7,0,1,2}) == 4);
        REQUIRE(solution.findPivot({4,5,6,7,8,1,2}) == 5);
        REQUIRE(solution.findPivot({4,5,6,7,8,9,2}) == 6);
    }

    SECTION("array size 4 with pivot")
    {
        REQUIRE(solution.findPivot({7,1,3,4}) == 1);
        REQUIRE(solution.findPivot({7,8,3,4}) == 2);
        REQUIRE(solution.findPivot({7,8,9,4}) == 3);
        REQUIRE(solution.findPivot({7,8,9,10}) == -1);
    }

    SECTION("array size 3 with pivot")
    {
        REQUIRE(solution.findPivot({7,1,3}) == 1);
        REQUIRE(solution.findPivot({7,8,3}) == 2);
        REQUIRE(solution.findPivot({7,8,9}) == -1);
    }

    SECTION("array size 2 with pivot")
    {
        REQUIRE(solution.findPivot({7,1}) == 1);
        REQUIRE(solution.findPivot({1,7}) == -1);
    }

    SECTION("No pivot point")
    {
        REQUIRE(solution.findPivot({}) == -1);
        REQUIRE(solution.findPivot({0}) == -1);
        REQUIRE(solution.findPivot({0,1}) == -1);
        REQUIRE(solution.findPivot({0,1,2}) == -1);
        REQUIRE(solution.findPivot({0,1,2,3,4,5,7}) == -1);
        REQUIRE(solution.findPivot({-7,1,2,3,4,5,7}) == -1);
    }
}

TEST_CASE("search", "[search]")
{
    Solution solution;

    SECTION("array size 7 with pivot")
    {
        vector v = {4,5,6,7,0,1,2};
        REQUIRE(solution.search(v, 4) == 0);
        REQUIRE(solution.search(v, 5) == 1);
        REQUIRE(solution.search(v, 6) == 2);
        REQUIRE(solution.search(v, 7) == 3);
        REQUIRE(solution.search(v, 0) == 4);
        REQUIRE(solution.search(v, 1) == 5);
        REQUIRE(solution.search(v, 2) == 6);
        REQUIRE(solution.search(v, 3) == -1);
        REQUIRE(solution.search(v, 8) == -1);
    }

    SECTION("array size 7 without pivot")
    {
        vector v = {-1,1,2,4,5,6,7};
        REQUIRE(solution.search(v, -1) == 0);
        REQUIRE(solution.search(v, 4) == 3);
        REQUIRE(solution.search(v, 5) == 4);
        REQUIRE(solution.search(v, 7) == 6);
    }

    SECTION("array size 4 with pivot")
    {
        REQUIRE(solution.search({7,1,3,4},7) == 0);
        REQUIRE(solution.search({7,8,3,4},8) == 1);
        REQUIRE(solution.search({7,8,3,4},4) == 3);
        REQUIRE(solution.search({7,8,9,4},4) == 3);
        REQUIRE(solution.search({7,8,9,4},7) == 0);
        REQUIRE(solution.search({7,8,9,4},5) == -1);
    }

    SECTION("array size 4 without pivot")
    {
        REQUIRE(solution.search({4,7,8,9},4) == 0);
        REQUIRE(solution.search({4,7,8,9},7) == 1);
        REQUIRE(solution.search({4,7,8,9},9) == 3);
        REQUIRE(solution.search({4,7,8,9},3) == -1);
        REQUIRE(solution.search({4,7,8,9},10) == -1);
    }

    SECTION("array size 3 with pivot")
    {
        REQUIRE(solution.search({7,1,3},7) == 0);
        REQUIRE(solution.search({7,1,3},1) == 1);
        REQUIRE(solution.search({7,1,3},3) == 2);
        REQUIRE(solution.search({7,1,3},0) == -1);
        REQUIRE(solution.search({7,1,3},5) == -1);
        REQUIRE(solution.search({7,1,3},8) == -1);
    }

    SECTION("array size 3 without pivot")
    {
        REQUIRE(solution.search({1,3,7},1) == 0);
        REQUIRE(solution.search({1,3,7},3) == 1);
        REQUIRE(solution.search({1,3,7},7) == 2);
        REQUIRE(solution.search({1,3,7},0) == -1);
        REQUIRE(solution.search({1,3,7},5) == -1);
        REQUIRE(solution.search({1,3,7},8) == -1);
    }

    SECTION("array size 2 with pivot")
    {
        REQUIRE(solution.search({7,1},7) == 0);
        REQUIRE(solution.search({7,1},1) == 1);
        REQUIRE(solution.search({7,1},5) == -1);
        REQUIRE(solution.search({7,1},8) == -1);
        REQUIRE(solution.search({7,1},0) == -1);
    }

    SECTION("array size 2 without pivot")
    {
        REQUIRE(solution.search({1,7},1) == 0);
        REQUIRE(solution.search({1,7},7) == 1);
        REQUIRE(solution.search({1,7},0) == -1);
        REQUIRE(solution.search({1,7},5) == -1);
        REQUIRE(solution.search({1,7},8) == -1);
    }
}

