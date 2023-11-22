#include <bits/stdc++.h>
using namespace std;
// sort the array prior, that's when we can use the idea of blaming everything on 'j'
// idea: 'the blame everything on j approach'
// 1) lets fixate our attention on the fact on checking whether nums[j] >= k, and nums[i] + nums[j] >= k ('blame everything on j')
// 2) an iteration is counted (count++) if nums[i] + nums[j] == k, if it's greater, j--, otherwise, i++, until i < j;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while (j >= 0 && nums[j] >= k)
        {
            j--;
        }
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                ans++;
                i++;
                j--;
            }
            else if ((nums[i] + nums[j]) >= k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};