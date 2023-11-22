#include <bits/stdc++.h>
using namespace std;
// idea: check frequency, then check ordering
// time complexity: O(n)
// to check ordering: maintain current index in the substring, and increment if (for x: t, index_s < s.size() && x == s[index_s]) -> checks if the order is being maintained
// the check for frequecies is bogus, and the ordering solves the question in itself

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // frequency (good to know, but bogus)
        unordered_map<int, int> freqMap1, freqMap2;
        for (auto &x : s)
        {
            freqMap1[x]++;
        }
        for (auto &x : t)
        {
            freqMap2[x]++;
        }
        int flag = 0;
        for (auto &x : s)
        {
            if (freqMap1[x] >= freqMap2[x] && !freqMap2[x])
            {
                flag = 0;
            }
        }
        flag = 1;
        // ordering (solves the question alone)
        int index_s = 0;
        for (auto &x : t)
        {
            if (index_s < s.size() && x == s[index_s])
            {
                index_s++;
            }
        }
        return index_s == s.size() && flag == 1; // can remove flag == 1 (bogus)
    }
};