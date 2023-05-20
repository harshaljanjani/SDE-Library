#include <bits/stdc++.h>
using namespace std;
// naive approach:
// idea: 1) map the element to its frequency in an unordered map/map freqMap
// 2) if the count/value in the key-value pair does not equal 1, it is a duplicate
// 3) add it to the result vector, and return the vector

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        unordered_map<int, int> freqMap;
        for (int i : nums)
        {
            freqMap[i]++;
        }
        for (auto [key, value] : freqMap)
        {
            if (value != 1)
            {
                result.push_back(key);
            }
        }
        return (result);
    }
};

// in-place approach and time complexity optimization:
// question: how could we use the following constraints to improve upon the naive solution?
// constraints: 1) numbers in the range of [1,n]
// 2) length of the array is n
// 3) frequency/count of the element is either 1 or 2
// idea: 1) flip the sign of a particular array index element *related to the elements value*, if it occurs once
// 2) check if the value has been negated before, as a sign that it has been visited before => therefore the array element currently visited is a duplicate

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        vector<int> res;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[abs(arr[i]) - 1] < 0)
            {
                res.push_back(abs(arr[i]));
            }
            else
            {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
        }
        return (res);
    }
};