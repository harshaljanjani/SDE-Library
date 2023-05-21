#include <bits/stdc++.h>
using namespace std;
// revision of merge sort => O(n*log(n))
// leetcode question - Sort An Array => O(nlogn) time complexity
// idea: two functions: merge(arr,l,m,r) and mergeSort(arr,l,r)
// 1) mergeSort(arr,l,r): recursive calls for the left half (l,m) and right half (m+1,r), and then merge both halves (l,m,r)
// 2) merge(arr,l,m,r):
// 2 a) first divide the array into two seperate arrays L[m-l+1] (includes the arr[mid]) and R[r-m]
// 2 b) then merge the arrays by the catching-up approach (conditional i++, j++, k++)
// 2 c) once all the sorted elements from L[m-l+1] and R[r-m] are exhausted, and i < n1 and j < n2, then *dump* the rest of the elements into the merged array

class Solution
{
    // utility functions
private:
    void merge(vector<int> &arr, int l, int m, int r)
    {
        // divide array into two halves
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[m + 1 + j];
        }
        // combine the two halves conditionally
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        // dump the rest
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);     // left half recursive call
            mergeSort(arr, m + 1, r); // right half recursive call
            merge(arr, l, m, r);      // merge halves
        }
    }
    // driver function
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return (nums);
    }
};