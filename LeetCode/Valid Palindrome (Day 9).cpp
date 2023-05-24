#include <bits/stdc++.h>
using namespace std;
// idea: 1) initialize two integer pointers, low = 0 and high = nums.size()-1
// 2) if either of s[low] or s[high] are non-alphanumeric, increment low by 1 or decrement high by 1 respectively, and *skip the current iteration of the rest of the loop*
// 3) if the tolower(s[low]) is not equal to the tolower(s[high]), then return false
// 4) if we reach the end of the loop without returning false, return true as it is a valid palindrome

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int low = 0, high = s.size() - 1;
        while (low <= high)
        {
            if (!isalpha(s[low]) && !isdigit(s[low]))
            {
                low++;
                continue;
            }
            if (!isalpha(s[high]) && !isdigit(s[high]))
            {
                high--;
                continue;
            }
            if (tolower(s[low]) != tolower(s[high]))
            {
                return (false);
            }
            low++;
            high--;
        }
        return (true);
    }
};