#include <bits/stdc++.h>
using namespace std;
// idea: two functions:
// 1) binarySearch: implementation of binary search, but the low and high are passed as input parameters to the function
// 2) getPivotIndex: the definition of the pivot index in a rotated sorted array is "the first element in the array that is not greater than the element before it"
// pay close attention to the conditions in the driver function, to shorten the scope of binary search to either [0, pivotIndex] or [pivotIndex, arr.size()-1]
// if the element is greater than the pivotElement, and is lesser than the first element in the rotated sorted array, then reduce search domain to [pivotIndex, arr.size()-1]
// else, reduce the search domain to [0, pivotIndex]
// notice we included pivotIndex in both search scopes, just to factor in edge cases such as:
/*
 1) array: [3,1], target: 3
 2) array: [1], target: 1
*/

class Solution
{
private:
    int getPivotIndex(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1, mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] >= arr[0])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return (high);
    }
    int binarySearch(vector<int> &arr, int low, int high, int target)
    {
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                return mid;
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
        return -1;
    }

public:
    int search(vector<int> &arr, int target)
    {
        int pivotIndex = getPivotIndex(arr);
        cout << pivotIndex << endl;
        int pivot = arr[pivotIndex];
        // pay close attention here
        if (target >= pivot && target < arr[0])
        {
            return binarySearch(arr, pivotIndex, arr.size() - 1, target);
        }
        else
        {
            return binarySearch(arr, 0, pivotIndex, target);
        }
    }
};