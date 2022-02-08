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

    set<pair<int,int>> completedPairs;

    for (int i=0; i < values.size(); ++i)
    {
        if (i > 0 && values[i] == values[i-1])
            continue; // shortcut: skip duplicates in this outer loop

        for (int j=i+1; j < values.size(); ++j)
        {
            auto pair = make_pair(values[i], values[j]);
            if (completedPairs.find(pair) != completedPairs.end())
                continue; // we've already evaluated this pair

            int need = 0 - values[i] - values[j];
            for (int k=j+1; k < values.size(); ++k)
            {
                if (values[k] == need)
                {
                    results.push_back({values[i],values[j],values[k]});
                    break;
                }
            }
            completedPairs.insert(pair);
        }
    }

    return results;
}

} // leetcode
