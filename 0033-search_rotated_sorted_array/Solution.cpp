#include "Solution.h"

namespace leetcode
{
using namespace std;

int Solution::search(const vector<int>& nums, int target)
{
    if (nums.empty())
        return -1;

    int start = 0;
    int end = nums.size() - 1;

    int pivot = findPivot(nums);
    if (pivot != -1)
    {
        // If target < nums[0] then it will be at or after
        // the pivot point else it will be before the pivot
        if (target < nums[0])
            start = pivot;
        else
            end = pivot - 1;
    }

    // Use binary search to achieve O(log n)
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (nums[middle] == target)
            return middle;
        else if (nums[middle] > target)
            end = middle - 1;
        else
            start = middle + 1;
    }
    return -1;
}

int Solution::findPivot(const std::vector<int>& nums)
{
    if (nums.size() < 2)
        return -1;

    int start = 0;
    int end = nums.size() - 1;
    int pivot = -1;

    // Use binary search to achieve O(log n)
    while (start < end)
    {
        int middle = (start + end) / 2;
        if (middle < nums.size()-1 && nums[middle] > nums[middle+1])
        {
            // when nums[i] > nums[i+1] we have found the pivot point
            pivot = middle + 1;
            break;
        }
        if (nums[middle] > nums[start])
            start = middle;
        else
            end = middle;
    }
    return pivot;
}

} // leetcode
