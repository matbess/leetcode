#include "Solution.h"
#include <algorithm>

namespace leetcode
{
using namespace std;

vector<vector<int>> Solution::merge(const vector<vector<int>>& intervals)
{
    if (intervals.size() == 1)
        return intervals;

    vector<vector<int>> result;
    vector<vector<int>> sorted = intervals;
    sort(sorted.begin(), sorted.end(),
        [](auto lhs, auto rhs) { return lhs[0] < rhs[0]; });

    int start = sorted[0][0];
    int end = sorted[0][1];

    for (int i = 1; i < sorted.size(); ++i)
    {
        if (sorted[i][0] > end)
        {
            result.push_back({start, end});
            start = sorted[i][0];
            end = sorted[i][1];
        }
        else if (sorted[i][1] > end)
        {
            end = sorted[i][1];
        }
    }
    result.push_back({start, end});
    return result;
}

} // leetcode
