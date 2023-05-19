#include <bits/stdc++.h>
using namespace std;
// idea: 1) map the element to its frequency in an unordered map/map freqMap
// 2) check if the frequencies are unique by adding them to a set data structure countSet
// 3) if the length/size of countSet is the same as the length of freqMap, the values of the number of occurences are unique with respect to each other

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freqMap;
        for (int i = 0; i < arr.size(); i++)
        {
            freqMap[arr[i]]++;
        }
        unordered_set<int> countSet;
        for (auto [element, count] : freqMap)
        {
            countSet.insert(count);
        }
        return (countSet.size() == freqMap.size());
    }
};