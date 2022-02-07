#include "Solution.h"

namespace leetcode
{
using namespace std;

vector<vector<int>> Solution::permute(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return vector<vector<int>> { nums };
    }
    
    if (nums.size() == 2)
    {
        return vector<vector<int>> { {nums[0], nums[1]}, {nums[1], nums[0]} };
    }

    vector<vector<int>> results;

    auto copy = nums;
    for (auto i = 0; i < nums.size(); ++i)
    {
        auto num = nums[i];
        copy.erase(find(copy.begin(), copy.end(), num));
        auto perms = permute(copy);
        for (auto perm : perms)
        {
            // add the current num into the permutation
            perm.push_back(num);
            results.push_back(perm);
        }
        // add num back into the set of all nums
        copy.push_back(num);
    }
    return results;
}

} // leetcode
