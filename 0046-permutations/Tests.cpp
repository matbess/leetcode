#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Solution.h"

using namespace std;
using namespace leetcode;

void VerifyResults(const vector<vector<int>>& results, vector<vector<int>>& expected)
{
    REQUIRE(results.size() > 0);
    REQUIRE(results.size() == expected.size());

    auto nums = expected[0].size();

    for (auto permutation : results)
    {
        REQUIRE(expected.size() != 0);
        REQUIRE(permutation.size() == nums);
        auto it = find(expected.begin(), expected.end(), permutation);
        REQUIRE(it != expected.end());
        auto s = expected.size();
        expected.erase(it);
        REQUIRE(expected.size() == s - 1);
    }
}

void PrintResults(const vector<vector<int>>& results)
{
    cout << "Results: { ";
    for (auto permutation : results)
    {
        cout << "{";
        for (auto i=0; i < permutation.size(); ++i)
        {
            cout << permutation[i];
            if (i < permutation.size() - 1) cout << ",";
        }
        auto sep = (permutation != results[results.size()-1]) ? ", " : " ";
        cout << "}" << sep;
    }
    cout << "}" << endl;
}

TEST_CASE("Permutations of different input sizes", "[permute]")
{
    Solution solution;

    SECTION("A single number")
    {
        vector<int> nums = { 0 };
        auto results = solution.permute(nums);
        vector<vector<int>> expected = { {0} };
        //PrintResults(results);
        VerifyResults(results, expected);
    }


    SECTION("Two numbers")
    {
        vector<int> nums = { 0, 1 };
        auto results = solution.permute(nums);
        vector<vector<int>> expected = { {0,1}, {1,0} };
        //PrintResults(results);
        VerifyResults(results, expected);
    }

    SECTION("Three sequential numbers")
    {
        vector<int> nums = { 0, 1, 2 };
        auto results = solution.permute(nums);
        vector<vector<int>> expected = { {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0} };
        //PrintResults(results);
        VerifyResults(results, expected);
    }

    SECTION("Five non-sequential numbers with edge cases")
    {
        vector<int> nums = { 10, -10, 3, 8, 5 };
        auto results = solution.permute(nums);
        vector<vector<int>> expected =
        {
            { 10, -10, 3, 8, 5 },{ -10, 10, 3, 8, 5 },{ 3, 10, -10, 8, 5 },{ 5, 10, -10, 8, 3 },{ 8, 10, -10, 5, 3 },
            { 10, -10, 3, 5, 8 },{ -10, 10, 3, 5, 8 },{ 3, 10, -10, 5, 8 },{ 5, 10, -10, 3, 8 },{ 8, 10, -10, 3, 5 },
            { 10, -10, 8, 3, 5 },{ -10, 10, 8, 3, 5 },{ 3, 10, 8, -10, 5 },{ 5, 10, 8, -10, 3 },{ 8, 10, 5, -10, 3 },
            { 10, -10, 8, 5, 3 },{ -10, 10, 8, 5, 3 },{ 3, 10, 8, 5, -10 },{ 5, 10, 8, 3, -10 },{ 8, 10, 5, 3, -10 },
            { 10, -10, 5, 3, 8 },{ -10, 10, 5, 3, 8 },{ 3, 10, 5, -10, 8 },{ 5, 10, 3, -10, 8 },{ 8, 10, 3, -10, 5 },
            { 10, -10, 5, 8, 3 },{ -10, 10, 5, 8, 3 },{ 3, 10, 5, 8, -10 },{ 5, 10, 3, 8, -10 },{ 8, 10, 3, 5, -10 },

            { 10, 3, -10, 8, 5 },{ -10, 3, 10, 8, 5 },{ 3, -10, 10, 8, 5 },{ 5, -10, 10, 8, 3 },{ 8, -10, 10, 5, 3 },
            { 10, 3, -10, 5, 8 },{ -10, 3, 10, 5, 8 },{ 3, -10, 10, 5, 8 },{ 5, -10, 10, 3, 8 },{ 8, -10, 10, 3, 5 },
            { 10, 8, -10, 3, 5 },{ -10, 8, 10, 3, 5 },{ 3, 8, 10, -10, 5 },{ 5, 8, 10, -10, 3 },{ 8, 5, 10, -10, 3 },
            { 10, 8, -10, 5, 3 },{ -10, 8, 10, 5, 3 },{ 3, 8, 10, 5, -10 },{ 5, 8, 10, 3, -10 },{ 8, 5, 10, 3, -10 },
            { 10, 5, -10, 3, 8 },{ -10, 5, 10, 3, 8 },{ 3, 5, 10, -10, 8 },{ 5, 3, 10, -10, 8 },{ 8, 3, 10, -10, 5 },
            { 10, 5, -10, 8, 3 },{ -10, 5, 10, 8, 3 },{ 3, 5, 10, 8, -10 },{ 5, 3, 10, 8, -10 },{ 8, 3, 10, 5, -10 },

            { 10, 3, 8, -10, 5 },{ -10, 3, 8, 10, 5 },{ 3, -10, 8, 10, 5 },{ 5, -10, 8, 10, 3 },{ 8, -10, 5, 10, 3 },
            { 10, 3, 5, -10, 8 },{ -10, 3, 5, 10, 8 },{ 3, -10, 5, 10, 8 },{ 5, -10, 3, 10, 8 },{ 8, -10, 3, 10, 5 },
            { 10, 8, 3, -10, 5 },{ -10, 8, 3, 10, 5 },{ 3, 8, -10, 10, 5 },{ 5, 8, -10, 10, 3 },{ 8, 5, -10, 10, 3 },
            { 10, 8, 5, -10, 3 },{ -10, 8, 5, 10, 3 },{ 3, 8, 5, 10, -10 },{ 5, 8, 3, 10, -10 },{ 8, 5, 3, 10, -10 },
            { 10, 5, 3, -10, 8 },{ -10, 5, 3, 10, 8 },{ 3, 5, -10, 10, 8 },{ 5, 3, -10, 10, 8 },{ 8, 3, -10, 10, 5 },
            { 10, 5, 8, -10, 3 },{ -10, 5, 8, 10, 3 },{ 3, 5, 8, 10, -10 },{ 5, 3, 8, 10, -10 },{ 8, 3, 5, 10, -10 },

            { 10, 3, 8, 5, -10 },{ -10, 3, 8, 5, 10 },{ 3, -10, 8, 5, 10 },{ 5, -10, 8, 3, 10 },{ 8, -10, 5, 3, 10 },
            { 10, 3, 5, 8, -10 },{ -10, 3, 5, 8, 10 },{ 3, -10, 5, 8, 10 },{ 5, -10, 3, 8, 10 },{ 8, -10, 3, 5, 10 },
            { 10, 8, 3, 5, -10 },{ -10, 8, 3, 5, 10 },{ 3, 8, -10, 5, 10 },{ 5, 8, -10, 3, 10 },{ 8, 5, -10, 3, 10 },
            { 10, 8, 5, 3, -10 },{ -10, 8, 5, 3, 10 },{ 3, 8, 5, -10, 10 },{ 5, 8, 3, -10, 10 },{ 8, 5, 3, -10, 10 },
            { 10, 5, 3, 8, -10 },{ -10, 5, 3, 8, 10 },{ 3, 5, -10, 8, 10 },{ 5, 3, -10, 8, 10 },{ 8, 3, -10, 5, 10 },
            { 10, 5, 8, 3, -10 },{ -10, 5, 8, 3, 10 },{ 3, 5, 8, -10, 10 },{ 5, 3, 8, -10, 10 },{ 8, 3, 5, -10, 10 }
        };
        //PrintResults(results);
        VerifyResults(results, expected);
    }
}

