#include <bits/stdc++.h>
using namespace std;
// idea: very similar to the *snowball approach* in "Move Zeroes (Day 14).cpp"
// 1) initialize 3 pointers, iter, low and high at 0
// 2) while s[iter] is not a whitespace, keep incrementing high and iter by 1 (here the snowballSize is defined by the size between low and high)
// 3) when a whitespace is encountered, we need to reverse the substring from low to high - 1 (one place before the whitespace encountered at s[iter])
// 4) after reversal, the value of low and high both equal *high + 1*
// 5) loop termination case: when the value of iter/high reaches s.size(), we need to explicitly write a conditional statement, stating that we want the last word reversed at iter == s.size(), otherwise the reverseString(nums,low,high) function would only reverse n - 1 words, and leave the last word as it is

class Solution
{
private:
    void reverseString(string &s, int low, int high)
    {
        while (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }

public:
    string reverseWords(string s)
    {
        int iter = 0, low = 0, high = 0;
        while (iter <= s.size())
        {
            // termination condition: iter == s.size() => perform reversal
            if (s[iter] == ' ' || iter == s.size())
            {
                reverseString(s, low, high - 1);
                low = high + 1;
                high += 1;
            }
            else
            {
                high++;
            }
            iter++;
        }
        return s;
    }
};