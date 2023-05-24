#include <bits/stdc++.h>
using namespace std;
// idea: 1) count the number of elements that are greater than the previous element, and for the last element, check if the last element is greater than the first element (in case of a rotated sorted array)
// 2) for a sorted array, count = 0, and for a sorted rotated array, count = 1
// 3) programatically, check if nums[i] > nums[(i+1) % nums.size()] (factors in the case, when i = nums.size()-1)
// 4) if the count is 0 or 1, return true

// solution 1:
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                count++;
            }
        }
        if (count <= 1)
        {
            return (true);
        }
        return (false);
    }
};

// solution 2:
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                count++;
            }
        }
        return (count == 1 && nums[nums.size() - 1] <= nums[0] || count == 0);
    }
};