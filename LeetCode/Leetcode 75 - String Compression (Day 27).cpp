#include <bits/stdc++.h>
using namespace std;
// idea (in-place): string compression involves taking a string, let's say "aaabbbc" and converting it into characters with frequencies, "a3b3c1". the goal is to find the length of this resultant string
// 2) we maintain two variables, 'i' the counter variable, and "res" the current index of the final string, which we would return by the end of the while loop as the final length of the resultant string
// 3) calculating groupLength is done through: while(i + groupLength < size), if(chars[i]  == chars[i + groupLength] && i + groupLength < s.size()), groupLength++;
// 4) the main logic lies in the statements chars[res++] = x && for(char x: to_string(groupLength)), chars[res++] = x;
// 5) increase i by the groupLength by the end of the outer while loop

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int res = 0, i = 0;
        while (i < chars.size())
        {
            int groupLength = 0;
            while (chars[i + groupLength] == chars[i] && i + groupLength < chars.size())
            {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1)
            {
                for (char &x : to_string(groupLength))
                {
                    chars[res++] = x;
                }
            }
            i += groupLength;
        }
        return res; // length of the final string
    }
};