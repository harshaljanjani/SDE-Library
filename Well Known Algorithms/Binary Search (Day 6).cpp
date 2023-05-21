#include <bits/stdc++.h>
using namespace std;
// revision of binary search => O(logn)
// idea: 1) low = 0, high = arr.size() - 1
// 2) if arr[mid] == target => return(element)
// 3) if arr[mid] > target => search in the lower half (high = mid - 1)
// 4) if arr[mid] < target => search in the upper half (low = mid + 1)

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                return (mid);
            }
            else
            {
                if (arr[mid] > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return (-1);
    }
};