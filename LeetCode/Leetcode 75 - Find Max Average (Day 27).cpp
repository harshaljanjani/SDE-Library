#include <bits/stdc++.h>
using namespace std;
// idea: 1) findMaxAverage uses the sliding window technique to find the maximum contiguous sum, hence giving us the maximum contiguous average, where the size of the sliding window is k.
// 2) a for loop is run to calculate the sum of the first window, and the sums of the subsequent windows are calculated by adding the next element (nums[i]), and subtracting the nums[i-k] element.

// approach: sliding window
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i;
        double sum = 0;
        double maxSum = INT_MIN;
        for (i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        maxSum = sum;
        while (i < nums.size())
        {
            sum -= nums[i - k];
            sum += nums[i];
            maxSum = max(sum, maxSum);
            i++;
        }
        return maxSum / k;
    }
};