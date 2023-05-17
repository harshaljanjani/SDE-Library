#include <bits/stdc++.h>
using namespace std;
// utility functions
// idea: keep searching in the lower half, and return last iteration
int findFirstOccurence(int *arr, int n, int target)
{
    // x is the target
    int low = 0, mid, high = n - 1, ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int element = arr[mid];
        if (target == element)
        {
            // don't be satisfied just yet, keep searching in the lower half
            ans = mid;
            high = mid - 1;
        }
        else
        {
            if (element > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return (ans);
}
// idea: keep searching in the upper half, and return last iteration
int findLastOccurence(int *arr, int n, int target)
{
    int low = 0, mid, high = n - 1, ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int element = arr[mid];
        if (target == element)
        {
            // don't be satisfied just yet, keep searching in the upper half
            ans = mid;
            low = mid + 1;
        }
        else
        {
            if (element > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return (ans);
}
// driver function
vector<int> find(int arr[], int n, int x)
{
    vector<int> res;
    res.push_back(findFirstOccurence(arr, n, x));
    res.push_back(findLastOccurence(arr, n, x));
    return (res);
}