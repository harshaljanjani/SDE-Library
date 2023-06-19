#include <bits/stdc++.h>
using namespace std;

// idea: 1) use the string.find(string substr) function in the C++ STL library, to return the index of the substring
// 2) use the string.erase(int start_index, length(substr)) function to erase the substring
// 3) repeat the process until length(string) != 0 and the there are one or more instances of the substring within the string left (i.e. s.find(substr) < s.length())
class Solution
{
public:
    string removeOccurrences(string s, string substr)
    {
        while (s.length() != 0 && s.find(substr) < s.length())
        {
            s.erase(s.find(substr), substr.length());
        }
        return (s);
    }
};