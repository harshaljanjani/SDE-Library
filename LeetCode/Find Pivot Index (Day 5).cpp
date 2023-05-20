#include <bits/stdc++.h>
using namespace std;
// optimized approach
// idea: 1) find the total sum of all elements in the array, and initialize a variable leftSum at 0
// 2) with each iteration, check if leftSum (sum of all elements to the left of nums[i]) is equal to (totalSum - leftSum - nums[i]), which is rightSum (nums[i] is excluded to calculate sum of all elements *strictly to the right* of nums[i])
// 3) add the current element to leftSum if the pivot is not found
// 4) if no pivot index is found, return -1

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // cout << sum - leftSum - nums[i] << " " << leftSum << endl;
            if (leftSum == sum - leftSum - nums[i])
            {
                return (i);
            }
            leftSum += nums[i];
        }
        return (-1);
    }
};