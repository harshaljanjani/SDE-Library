#include <bits/stdc++.h>
using namespace std;
// idea: refer to "Merge Sort.cpp" in the "Well Known Algorithms" folder
// in-place solution: reviewed in-place solutions, the crux is that you start from int p = n1 + n2 - 1, and replace backwards;
// whenever such minor overlaps occur in your in-place solutions, *think* if you could overcome it by just starting from the last index instead?
// 1) create a third array of size n1 + n2, merge into that and replace elements of nums1, by nums1.assign(nums3.begin(), nums3.end())

class Solution
{
public:
    void merge(vector<int> &nums1, int n1, vector<int> &nums2, int n2)
    {
        vector<int> nums3(n1 + n2);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                nums3[k] = nums1[i];
                i++;
            }
            else
            {
                nums3[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
        nums1.assign(nums3.begin(), nums3.end());
    }
};