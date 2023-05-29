#include <bits/stdc++.h>
using namespace std;
// cyclic rotation of array by k times (in-place optimized algorithm)

// example: [[1,2,3,4,5] , [6,7,8]], k = 3 (the length of the right half of the array = k)
// idea: 1) rotate the first half of the array from [0, n-k-1] (formulae deduced from example dry runs)
// output from 1) => [[5,4,3,2,1] , [6,7,8]]
// 2) rotate the second half of the array from [n-k to n-1]
// output from 2) => [[5,4,3,2,1] , [8,7,6]]
// 3) rotate the entire array from [0 to n-1]
// output from 3) => [[6,7,8], [1,2,3,4,5]] => [6,7,8,1,2,3,4,5]

class Solution
{
private:
    void reverse(vector<int> &arr, int low, int high)
    {
        while (low < high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        // mistake (forgot edge case optimization): k = k % n (check if k is in range)
        k %= n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};