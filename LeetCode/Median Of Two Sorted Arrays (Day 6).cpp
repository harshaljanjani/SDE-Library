#include <bits/stdc++.h>
using namespace std;
// idea: 1) merge the two sorted arrays (based on the pre-requisite merge sort algorithm in the well-known algorithms folder) and calculate the median
// 2) if the length of the array is even, the median is (double)(arr[mid] + arr[mid-1])/2
// 3) if the length of the array is odd, the median is arr[mid]

class Solution
{
private:
    vector<int> merge(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> arr(nums1.size() + nums2.size()); // without size initialization it would throw an error
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0;
        int j = 0;
        int k = 0;
        // combine the two arrays
        while (i < n1 && j < n2)
        {
            if (nums1[i] <= nums2[j])
            {
                arr[k] = nums1[i];
                i++;
            }
            else
            {
                arr[k] = nums2[j];
                j++;
            }
            k++;
        }
        // dump the rest
        while (i < n1)
        {
            arr[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = nums2[j];
            j++;
            k++;
        }
        return (arr);
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> mergedArr = merge(nums1, nums2);
        int mid = mergedArr.size() / 2;
        if (mergedArr.size() % 2 == 0)
        {
            return (double)(mergedArr[mid] + mergedArr[mid - 1]) / 2; // pay attention to the parantheses here (around the sum, not the whole divide) => with parantheses around the divide, it gets truncated early
        }
        else
        {
            return (double)(mergedArr[mid]);
        }
    }
};