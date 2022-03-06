#include "Solution.h"

#include <iostream>
using namespace std;

namespace leetcode
{
// Constraints: 1 <= n <= 500
int Solution::countOrders(int n)
{
    unsigned long long total = 1;

    // total(i) = total(i-1) * ((2i-1)+(2i-2)+...+1)
    for (int i=2; i <= n; ++i)
    {
        unsigned long long sum = 0;
        int twoi = 2 * i;
        for (int j=1; j < twoi; ++j)
            sum += twoi - j;
        total = (total * sum) % 1000000007;
    }
    return total;
}

} // leetcode
