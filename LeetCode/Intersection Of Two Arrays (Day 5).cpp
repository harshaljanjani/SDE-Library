#include <bits/stdc++.h>
using namespace std;
// naive approach
// idea: 1) if nums1.size() > nums2.size(), we have to search *all the elements of nums2 in nums1*, since the maximum intersection can be the array with the lesser size, in this case nums2 (and vice-versa)
// STL functions: use find(iter.begin(),iter.end(),value) != / == iter.end()

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> intersectionSet;
        if (nums1.size() >= nums2.size())
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                if (find(nums1.begin(), nums1.end(), nums2[i]) != nums1.end() && find(intersectionSet.begin(), intersectionSet.end(), nums2[i]) == intersectionSet.end())
                {
                    intersectionSet.push_back(nums2[i]);
                }
            }
        }
        else
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end() && find(intersectionSet.begin(), intersectionSet.end(), nums1[i]) == intersectionSet.end())
                {
                    intersectionSet.push_back(nums1[i]);
                }
            }
        }
        return (intersectionSet);
    }
};

// optimized solution:
// idea: 1) sort both the arrays in ascending order
// 2) initialize two integer pointers, i and j at 0, for nums1 and nums2 respectively
// 3) if nums1[i] > nums2[j]: for j to catch up to i, increase j
// 4) if nums2[j] > nums1[i]: for i to catch up to j, increase i
// 5) if nums1[i] == nums2[j]: i and j have catched up to each other, insert into the result vector (equal elements / intersection)
// 6) erase all duplicates in the final result vector

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        result.erase(unique(result.begin(), result.end()), result.end());
        return (result);
    }
};