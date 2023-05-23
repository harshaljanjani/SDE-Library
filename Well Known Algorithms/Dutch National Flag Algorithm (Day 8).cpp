#include <bits/stdc++.h>
using namespace std;
// in Love Babbar's DSA sheet as "Sort An Array With 0s, 1s And 2s"
// idea: 1) initialize three pointers iter = 0, low = 0 and high = n - 1
// 2) if arr[iter] = 1, increment iter by 1
// 3) else arr[iter] = 2, decrement high by 1 (we do not increment iter by 1 for arr[iter] = 2, proven by dry run => in essence, you need to check again if the swapped element from arr[high] to arr[iter] was 2, then you may need to swap it for a second time)
// 4) else if arr[iter] = 0, increment iter by 1 and low by 1
// 5) repeat this process until iter > high (while iter <= high)

class Solution
{
public:
    void sort012(int *arr, int n)
    {
        int iter = 0, low = 0, high = n - 1;
        while (iter <= high)
        {
            if (arr[iter] == 0)
            {
                swap(arr[iter], arr[low]);
                iter++;
                low++;
            }
            else if (arr[iter] == 1)
            {
                iter++;
            }
            else
            {
                swap(arr[high], arr[iter]);
                high--;
            }
        }
    }
};