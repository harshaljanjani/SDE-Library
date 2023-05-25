#include <bits/stdc++.h>
using namespace std;
// idea (brute force): check each and every contiguous subarray within the array, to find the maximum sum
// optimized using dynamic programming (check "Kadane's Algorithm (Day 11).cpp" in the "Well Known Algorithms" folder)

// brute force approach (ranges of pointers):
// i -> traversal pointer (0 to len - 1)
// j -> from i to the len - 1 (ending points of subarrays)
// k -> a) each element from i to j is added to the sum, and the sum is compared to max_sum at the end
// b) the sum is reset to 0 immediately after the k = [i, j] loop
// time complexity: O(n^3)
int get_maxsum(int *arr, int len)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

// driver function
int main(void)
{
    int len;
    cout << "Enter The Array Length" << endl;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    int sum = get_maxsum(arr, len);
    cout << "The Maximum Subarray Sum Is: " << sum << endl;
}