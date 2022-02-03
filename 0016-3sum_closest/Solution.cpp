#include "Solution.h"
#include <cmath>

namespace leetcode
{
using namespace std;

int Solution::threeSumClosest(const vector<int>& nums, int target)
{
    int closest = 100000; // init to value larger than max
    for (int i=0; i < nums.size(); ++i)
    {
        for (int j=i+1; j < nums.size(); ++j)
        {
            int twosum = nums[i] + nums[j];
            for (int x=j+1; x < nums.size(); ++x)
            {
                int threesum = twosum + nums[x];
                if (abs(target - threesum) < abs(target - closest))
                {
                    closest = threesum;
                }
            }
        }
    }
    return closest;
}

} // leetcode
