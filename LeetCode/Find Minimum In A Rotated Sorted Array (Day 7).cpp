#include <bits/stdc++.h>
using namespace std;
// idea: 1) find the pivot index (refer to "Find Pivot Index (Day 6).cpp")
// 2) the minimum element would be at the pivot index, or at 0 (edge cases include the array not rotated at all or rotated (n-1) times)
// 3 a) example: [1,2,3,4,5] => without optimization for edge case, code returns "5"
// 3 b) [2,1] => without optimization for edge case, code returns "2"

class Solution
{
private:
    int getPivotIndex(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1, mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] >= arr[0])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return (high);
    }

public:
    int findMin(vector<int> &nums)
    {
        int pivotIndex = getPivotIndex(nums);
        // how I dealt with the edge case initially:
        // return nums[(pivotIndex != nums.size()-1) ? pivotIndex : 0];
        // why was I wrong?: check the edge case [2,1]
        // expected output: 1, got output: 2

        // correct way to deal with the edge case
        return (min(nums[pivotIndex], nums[0]));
    }
};