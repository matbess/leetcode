#include "Solution.h"

namespace leetcode
{
using namespace std;

void Solution::nextPermutation(std::vector<int>& nums)
{
    if (nums.size() == 1)
        return;

    bool swapNeeded = false;
    int swapLeft = 0;
    for (int i = nums.size() - 2; i >= 0; --i)
    {
        if (nums[i] < nums[i+1])
        {
            swapLeft = i;
            swapNeeded = true;
            break;
        }
    }

    if (swapNeeded)
    {
        int swapRight = swapLeft + 1;
        for (int j = swapRight + 1; j < nums.size(); ++j)
        {
            if (nums[j] <= nums[swapRight] && nums[j] > nums[swapLeft])
            {
                swapRight = j;
            }
        }
        auto tmp = nums[swapLeft];
        nums[swapLeft] = nums[swapRight];
        nums[swapRight] = tmp;
    }

    int startReversing = swapNeeded ? swapLeft + 1 : 0;
    for (int i=startReversing, j=nums.size()-1; i < j; ++i, --j)
    {
        auto x = nums[i];
        nums[i] = nums[j];
        nums[j] = x;
    }
}

} // leetcode
