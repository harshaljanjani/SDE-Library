#include <bits/stdc++.h>
using namespace std;
// idea: refer to "Find First And Last Occurence Of An Element In A Sorted Array (Day 2).cpp" in the "Searching And Sorting" folder

class Solution
{
private:
    int find_first_occurence(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1, mid, ans = -1;
        // check this condition, mistake: (while (low < high))
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                ans = mid;
                high = mid - 1;
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
        return ans;
    }
    int find_last_occurence(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1, mid, ans = -1;
        // check this condition, mistake: (while (low < high))
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                ans = mid;
                low = mid + 1;
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
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        int lowest = find_first_occurence(nums, target);
        int highest = find_last_occurence(nums, target);
        res.push_back(lowest);
        res.push_back(highest);
        return res;
    }
};