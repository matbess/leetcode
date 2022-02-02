#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"
#include "Solution.h"

using namespace std;
using namespace leetcode;

class TestSolution : public Solution
{
public:
    // expose protected methods for tests
    int findFirst(const vector<int>& nums, int target) { return Solution::findFirst(nums, target); }
    int findLast(const vector<int>& nums, int target) { return Solution::findLast(nums, target); }
};

TEST_CASE("findFirst", "[findFirst]")
{
    TestSolution solution;

    SECTION("Small array with duplicates")
    {
        vector<int> v = {5,7,7,8,8,10};
        REQUIRE(solution.findFirst(v, 5) == 0);
        REQUIRE(solution.findFirst(v, 7) == 1);
        REQUIRE(solution.findFirst(v, 8) == 3);
        REQUIRE(solution.findFirst(v, 10) == 5);
    }

    SECTION("Find first at every position in array of size six")
    {
        REQUIRE(solution.findFirst({7,8,8,8,10,13}, 7) == 0);
        REQUIRE(solution.findFirst({7,7,8,8,10,13}, 7) == 0);
        REQUIRE(solution.findFirst({5,7,7,8,8,10}, 7) == 1);
        REQUIRE(solution.findFirst({5,5,7,7,8,10}, 7) == 2);
        REQUIRE(solution.findFirst({5,5,5,7,7,10}, 7) == 3);
        REQUIRE(solution.findFirst({5,5,5,5,7,7}, 7) == 4);
        REQUIRE(solution.findFirst({5,5,5,5,5,7}, 7) == 5);
    }

    SECTION("Entire array is same number")
    {
        vector<int> v = {7,7,7,7,7,7};
        REQUIRE(solution.findFirst(v, 7) == 0);
        REQUIRE(solution.findFirst(v, 5) == -1);
    }

    SECTION("All but one matches")
    {
        REQUIRE(solution.findFirst({7,7,7,7,7,8}, 7) == 0);
        REQUIRE(solution.findFirst({-7,7,7,7,7,7}, 7) == 1);
    }

    SECTION("Three entries")
    {
        vector<int> v = {7,7,8};
        REQUIRE(solution.findFirst(v, 7) == 0);
        REQUIRE(solution.findFirst(v, 8) == 2);
        REQUIRE(solution.findFirst(v, 9) == -1);
        REQUIRE(solution.findFirst({6,7,8}, 7) == 1);
    }

    SECTION("Two entries")
    {
        vector<int> v = {7,8};
        REQUIRE(solution.findFirst(v, 7) == 0);
        REQUIRE(solution.findFirst(v, 8) == 1);
        REQUIRE(solution.findFirst(v, 9) == -1);
    }

    SECTION("Single entry")
    {
        vector<int> v = {7};
        REQUIRE(solution.findFirst(v, 7) == 0);
        REQUIRE(solution.findFirst(v, -5) == -1);
    }

    SECTION("Empty array")
    {
        REQUIRE(solution.findFirst({}, 7) == -1);
    }
}

TEST_CASE("findLast", "[findLast]")
{
    TestSolution solution;

    SECTION("Small array with duplicates")
    {
        vector<int> v = {5,7,7,8,8,10};
        REQUIRE(solution.findLast(v, 5) == 0);
        REQUIRE(solution.findLast(v, 7) == 2);
        REQUIRE(solution.findLast(v, 8) == 4);
        REQUIRE(solution.findLast(v, 10) == 5);
    }

    SECTION("Find last at every position in array of size six")
    {
        REQUIRE(solution.findLast({7,8,8,8,10,13}, 7) == 0);
        REQUIRE(solution.findLast({7,7,8,8,10,13}, 7) == 1);
        REQUIRE(solution.findLast({5,7,7,8,8,10}, 7) == 2);
        REQUIRE(solution.findLast({5,5,7,7,8,10}, 7) == 3);
        REQUIRE(solution.findLast({5,5,5,7,7,10}, 7) == 4);
        REQUIRE(solution.findLast({5,5,5,5,7,7}, 7) == 5);
        REQUIRE(solution.findLast({5,5,5,5,5,7}, 7) == 5);
    }

    SECTION("Entire array is same number")
    {
        vector<int> v = {7,7,7,7,7,7};
        REQUIRE(solution.findLast(v, 7) == 5);
        REQUIRE(solution.findLast(v, 5) == -1);
    }

    SECTION("All but one matches")
    {
        REQUIRE(solution.findLast({7,7,7,7,7,8}, 7) == 4);
        REQUIRE(solution.findLast({-7,7,7,7,7,7}, 7) == 5);
    }

    SECTION("Three entries")
    {
        vector<int> v = {7,7,8};
        REQUIRE(solution.findLast(v, 7) == 1);
        REQUIRE(solution.findLast(v, 8) == 2);
        REQUIRE(solution.findLast(v, 9) == -1);
        REQUIRE(solution.findLast({6,7,8}, 7) == 1);
    }

    SECTION("Two entries")
    {
        vector<int> v = {7,8};
        REQUIRE(solution.findLast(v, 7) == 0);
        REQUIRE(solution.findLast(v, 8) == 1);
        REQUIRE(solution.findLast(v, 9) == -1);
    }

    SECTION("Single entry")
    {
        vector<int> v = {7};
        REQUIRE(solution.findLast(v, 7) == 0);
        REQUIRE(solution.findLast(v, -5) == -1);
    }

    SECTION("Empty array")
    {
        REQUIRE(solution.findLast({}, 7) == -1);
    }
}

TEST_CASE("searchRange", "[searchRange]")
{
    Solution solution;

    SECTION("Empty array")
    {
        REQUIRE(solution.searchRange({}, 7) == vector<int>{-1,-1});
    }

    SECTION("Single entry")
    {
        vector<int> v = {7};
        REQUIRE(solution.searchRange(v, 7) == vector<int>{0,0});
        REQUIRE(solution.searchRange(v, -5) == vector<int>{-1,-1});
    }

    SECTION("Duplicates in middle of array")
    {
        vector<int> v = {5,7,7,8,8,10};
        REQUIRE(solution.searchRange(v, 5) == vector<int>{0,0});
        REQUIRE(solution.searchRange(v, 7) == vector<int>{1,2});
        REQUIRE(solution.searchRange(v, 8) == vector<int>{3,4});
        REQUIRE(solution.searchRange(v, 10) == vector<int>{5,5});
        REQUIRE(solution.searchRange(v, 11) == vector<int>{-1,-1});
    }

    SECTION("Max size target")
    {
        REQUIRE(solution.searchRange({-1000000000,7,7,8,8,10,1000000000}, 7) == vector<int>{1,2});
        REQUIRE(solution.searchRange(
            {-1000000000,7,7,8,8,10,1000000000,1000000000,1000000000}, 1000000000) == vector<int>{6,8});
    }

    SECTION("Many items")
    {
        vector<int> v = {5,7,7,
                         8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,
                         8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,
                         8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,
                         8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,
                         8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,
                         10,10,15,15,18,35,1000000000};
        REQUIRE(solution.searchRange(v, 1) == vector<int>{-1,-1});
        REQUIRE(solution.searchRange(v, 5) == vector<int>{0,0});
        REQUIRE(solution.searchRange(v, 7) == vector<int>{1,2});
        REQUIRE(solution.searchRange(v, 8) == vector<int>{3,102});
        REQUIRE(solution.searchRange(v, 10) == vector<int>{103,104});
        REQUIRE(solution.searchRange(v, 15) == vector<int>{105,106});
        REQUIRE(solution.searchRange(v, 18) == vector<int>{107,107});
        REQUIRE(solution.searchRange(v, 35) == vector<int>{108,108});
        REQUIRE(solution.searchRange(v, 50) == vector<int>{-1,-1});
        REQUIRE(solution.searchRange(v, 1000000000) == vector<int>{109,109});
    }
}

