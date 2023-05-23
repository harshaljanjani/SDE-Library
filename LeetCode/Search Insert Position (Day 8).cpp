#include <bits/stdc++.h>
using namespace std;
// idea: modified binary search approach
// how did I handle the edge cases better now than I did months ago?
// edge cases: 1) array = [1,3,6,8], target = 9
// 2) array = [1,3,6,8], target = 0
// if even by the end, *ans = -1* as it was initialized, this implies that we kept looking in the upper half of the array (arr[mid] was always lesser than target), and in this process we exhausted the whole length of the array
// this implies that the target is greater than every single element in the array (the array is sorted), and it *must be inserted at the (lastindex + 1) index* , which is arr.size() itself

class Solution
{
public:
    int searchInsert(vector<int> &arr, int target)
    {
        // months ago, I used these hard-coded edge case optimizations
        /*
        if (target < arr[0])
        {
            return (0);
        }
        else if (target > arr[arr.size()-1])
        {
            return (arr.size());
        }
        */
        int low = 0, high = arr.size() - 1, mid, ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                return (mid);
            }
            else
            {
                if (arr[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    ans = mid;
                    high = mid - 1;
                }
            }
        }
        // my solution to the edge cases now
        return ((ans != -1) ? ans : arr.size());
    }
};