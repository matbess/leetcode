#include "Solution.h"

namespace leetcode
{

double Solution::champagneTower(int poured, int query_row, int query_glass)
{
    const int NUM_ROWS = 100;
    double cups[NUM_ROWS+1][NUM_ROWS+1] = {};

    cups[0][0] = poured;

    for (int i=1; i < NUM_ROWS; ++i)
    {
        bool rowHasOverflow = false;
        for (int j=0; j < i; ++j)
        {
            double cupAbove = cups[i-1][j];
            if (cupAbove > 1.0)
            {
                double overflowSplit = (cupAbove - 1.0) / 2;
                cups[i][j] += overflowSplit;
                cups[i][j+1] += overflowSplit;
                cups[i-1][j] = 1.0;

                if (cups[i][j] > 1.0)
                    rowHasOverflow = true;
            }
        }

        if (!rowHasOverflow)
            break;
    }

    return cups[query_row][query_glass];
}

} // leetcode
