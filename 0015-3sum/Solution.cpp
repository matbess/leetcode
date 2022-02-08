#include "Solution.h"

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
            // Using O(log n) binary search for this nested loop
            // gives a big runtime performance improvement over
            // simply iterating O(n) over the entire values array.
            int start = j+1;
            int end = values.size() - 1;
            while (start <= end)
            {
                int middle = (start + end) / 2;
                // If the value at nums[middle] is >= target then search
                // earlier in the array else search later in the array
                if (values[middle] >= need)
                {
                    if (values[middle] == need)
                    {
                        results.push_back({values[i],values[j],values[middle]});
                        break;
                    }
                    end = middle - 1;
                }
                else
                    start = middle + 1;
            }
        }
    }

    return results;
}

} // leetcode
