#include <iostream>
#include <vector>
#include <algorithm>
// idea: 1) left = leftmost index of the current sub-array, globalMax = maximum length of sub-array, count = count of zeros
// 2) count++; (nums[i] == 0), if the current is zero; while(count > k), if the leftmost element is 0, then count--, and increase left
// 3) globalMax = max(globalMax, i-left+1);

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int globalMax = 0;
        int count = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                count++;
            }
            while (count > k)
            {
                if (nums[left] == 0)
                {
                    count--;
                }
                left++;
            }
            globalMax = max(globalMax, i - left + 1);
        }
        return globalMax;
    }
};