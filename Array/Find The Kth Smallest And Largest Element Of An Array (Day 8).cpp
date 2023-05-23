#include <bits/stdc++.h>
using namespace std;
// method 1: using a comparator and qsort()
// note: this is more of a C-oriented methodology, C++ has it much simpler
// idea: 1) understand the working of the qsort(arr,*number of elements in the array*,sizeof(int),*comparator*) function
// 2) a comparator, if reordering the array in ascending order, would return 1 or any positive integer if (p > q) i.e. first element checked > next element checked in order, -1 or any negative integer if (p < q) i.e. first element checked < next element checked in order and 0 if both p and q are equal in value
// 3) the kth smallest element of an array arranged in ascending order would be arr[k-1] (ex: 2nd smallest element would be at index 1)
// 4) the kth largest element of an array arranged in ascending order would be arr[r - k + 1] (ex: 2nd largest element of an array of length 6 would be at position 6 - 2 + 1 = 5)

// method 2: use sort(arr, arr+n), where n = (r - l + 1)

class Solution
{
private:
    static int comparator(const void *a, const void *b)
    {
        const int *p = (int *)a;
        const int *q = (int *)b;
        return (*p - *q);
    }

public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    vector<int> kthSmallest(int arr[], int l, int r, int k)
    {
        vector<int> res;
        qsort(arr, r - l + 1, sizeof(int), comparator);
        res.push_back(arr[k - 1]);     // kth smallest element
        res.push_back(arr[r - k + 1]); // kth largest element
        return (res);
    }
};