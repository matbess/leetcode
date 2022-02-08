#include "Solution.h"
#include <set>

namespace leetcode
{
using namespace std;

std::vector<std::vector<int>> Solution::threeSum(const std::vector<int>& nums)
{
    vector<vector<int>> results;

    if (nums.size() < 3)
        return results;

    auto values = nums;
    sort(values.begin(), values.end());

    for (int i=0; i < values.size(); ++i)
    {
        if (i > 0 && values[i] == values[i-1])
            continue; // shortcut: skip duplicates in this outer loop

        for (int j=i+1; j < values.size(); ++j)
        {
            // Skip duplicates except for when i was just incremented (j-1 == i)
            if (j-1 > i && j > 0 && values[j] == values[j-1])
                continue;

            int need = 0 - values[i] - values[j];
            for (int k=j+1; k < values.size(); ++k)
            {
                if (values[k] >= need)
                {
                    if (values[k] == need)
                        results.push_back({values[i],values[j],values[k]});
                    break;
                }
            }
        }
    }

    return results;
}

} // leetcode
