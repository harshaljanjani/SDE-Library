#include <bits/stdc++.h>
using namespace std;
// modified binary search approach
// why can we still apply binary search? => the array is divided into two sections, each of which are sorted - one ascending and the other descending
// idea: 1) if arr[mid] < arr[mid+1] => we can look further right for the peak, because we expect the peak to be higher (low = mid + 1)
// 2) if arr[mid] > arr[mid + 1] => we may have just reached the peak and are starting a downward descent, hence (high = *mid* NOT (mid - 1), because we want to include the peak as *high* in our next iteration)
// 3) return(high / low) => returns the peak (at the last iteration, low == high and the while loop terminates)

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1, mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            // search higher
            if (arr[mid + 1] > arr[mid])
            {
                low = mid + 1;
            }
            // may begin a downward descent, retain peak
            else
            {
                high = mid;
            }
        }
        return (high);
    }
};