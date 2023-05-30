// idea: not naive
// leetCode (medium) level problem
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();
        // target compared to the element (expected row, expected column)
        // define low and high
        int low = 0, high = (rows * columns) - 1, mid, element;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            // define which element you expect mid to be?
            element = matrix[mid / columns][mid % columns];
            if (target == element)
            {
                return (true);
            }
            else
            {
                if (element > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return (false);
    }
};