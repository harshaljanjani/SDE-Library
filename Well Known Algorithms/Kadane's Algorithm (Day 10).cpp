#include <bits/stdc++.h>
using namespace std;
// aim: used for finding the largest contiguous subarray
// resource link: https://shorturl.at/lLQR8 (CS Dojo) => pay attention to proof of kadane's algorithm
// in Love Babbar's DSA Sheet as "Kadane's Algorithm (V.V.V.I)"
// idea: 1) initialize max_current to nums[0] => keeps track of the maximum sum subarray till the current index
// 2) initialize max_global to nums[0] => keeps track of the global maximum sum
// 3) proven that the maximum sum subarray till a given index i is either nums[i], or max_current + nums[i]
// 4) at every iteration, assign max_current to max(max_current+nums[i], nums[i])
// 5) after completing step 4, assign max_global to max(max_global, max_current) at each iteration

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_global = nums[0], max_current = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            max_current = max(nums[i], max_current + nums[i]);
            if (max_current > max_global)
            {
                max_global = max_current;
            }
        }
        return max_global;
    }
};