#include "Solution.h"

namespace leetcode
{
using namespace std;

vector<int> Solution::searchRange(const vector<int>& nums, int target)
{
    return {findFirst(nums, target), findLast(nums, target)};
}

int Solution::findFirst(const vector<int>& nums, int target)
{
    int index = -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (nums[middle] >= target)
        {
            if (nums[middle] == target)
                index = middle;
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return index;
}

int Solution::findLast(const vector<int>& nums, int target)
{
    int index = -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (nums[middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            if (nums[middle] == target)
                index = middle;
            start = middle + 1;
        }
    }
    return index;
}

} // leetcode
