#define CATCH_CONFIG_MAIN
#include <iostream>
#include <algorithm>
#include "catch.hpp"
#include "Solution.h"

using namespace std;
using namespace leetcode;

void PrintResults(const string& intro, const vector<int>& permutation)
{
    cout << intro << "{";
    for (auto i=0; i < permutation.size(); ++i)
    {
        cout << permutation[i];
        if (i < permutation.size() - 1) cout << ",";
    }
    cout << "}" << endl;
}

void CheckSolution(const vector<int>& numbers)
{
    auto stlAnswer = numbers;
    std::next_permutation(stlAnswer.begin(), stlAnswer.end());

    auto myAnswer = numbers;
    Solution solution;
    solution.nextPermutation(myAnswer);

    //PrintResults(" stl: ", stlAnswer);
    //PrintResults("mine: ", myAnswer);

    REQUIRE(myAnswer == stlAnswer);
}

TEST_CASE("", "[nextPermutation]")
{
    SECTION("Min/max values")
    {
        CheckSolution({0,1,2,3,100});
        CheckSolution({100,0});
        CheckSolution({100,0,100,0,100});
    }

    SECTION("Min/max number of values")
    {
        CheckSolution({0});
        CheckSolution({100});
        CheckSolution({
            0,1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8,9,
            0,1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8,9,
            0,1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8,9,
            0,1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8,9,
            0,1,2,3,4,5,6,7,8,9, 0,1,2,3,4,5,6,7,8,9
            });

        CheckSolution({
            0,99,98,97,96,95,94,93,92,91,90,
            89,88,87,86,85,84,83,82,81,80,
            79,78,77,76,75,74,73,72,71,70,
            69,68,67,66,65,64,63,62,61,60,
            59,58,57,56,55,54,53,52,51,50,
            49,48,47,46,45,44,43,42,41,40,
            39,38,37,36,35,34,33,32,31,30,
            29,28,27,26,25,24,23,22,21,20,
            19,18,17,16,15,14,13,12,11,10,
            9,8,7,6,5,4,3,2,1});
    }

    SECTION("No more permutations")
    {
        CheckSolution({3,2,1});
        CheckSolution({100,3,2,1,0});
        CheckSolution({
            99,98,97,96,95,94,93,92,91,90,
            89,88,87,86,85,84,83,82,81,80,
            79,78,77,76,75,74,73,72,71,70,
            69,68,67,66,65,64,63,62,61,60,
            59,58,57,56,55,54,53,52,51,50,
            49,48,47,46,45,44,43,42,41,40,
            39,38,37,36,35,34,33,32,31,30,
            29,28,27,26,25,24,23,22,21,20,
            19,18,17,16,15,14,13,12,11,10,
            9,8,7,6,5,4,3,2,1,0});
    }

    SECTION("Sequential duplicates")
    {
        CheckSolution({1,2,7,3,3});
        CheckSolution({1,2,7,3,3,3});
        CheckSolution({1,2,3,3,3,7});
        CheckSolution({1,1,1,2,1,1,1});
        CheckSolution({1,1,1,0,1,1,1});
        CheckSolution({1,1,1,1,1,1,1,1,1,1,1,1,1});
    }
}

