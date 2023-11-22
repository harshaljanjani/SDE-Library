#include <bits/stdc++.h>
using namespace std;
// idea: sliding window technique (similar to 'find max average (day 27).cpp')

class Solution
{
public:
    bool isVowel(char i)
    {
        i = tolower(i);
        set s = {'a', 'e', 'i', 'o', 'u'};
        if (s.find(i) != s.end())
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k)
    {
        int maxVowel = INT_MIN;
        int vowel = 0, i;
        for (i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
            {
                vowel++;
            }
        }
        maxVowel = max(vowel, maxVowel);
        while (i < s.size())
        {
            if (isVowel(s[i]))
            {
                vowel++;
            }
            if (isVowel(s[i - k]))
            {
                vowel--;
            }
            maxVowel = max(vowel, maxVowel);
            i++;
        }
        return maxVowel;
    }
};