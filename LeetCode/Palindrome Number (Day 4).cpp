#include <bits/stdc++.h>
using namespace std;
// the library/module <limits.h> contains the definition of INT_MAX and INT_MIN

// reference: similar to the question "Reverse Integer (Day 3).cpp"
// idea: find the reversed integer and check if it's the same as the integer itself
// edge cases: 1) if the number is negative, it's not a palindrome (ex: -121 -> 121-)
// 2) if the reversed number is greater than INT_MAX, it must not be accepted

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // deal with edge case
        if (x < 0)
        {
            return (false);
        }
        // main logic
        int rev = 0, temp = x;
        while (x != 0)
        {
            // check if the reversed number is in range of the INT datatype (< INT_MAX)
            if (rev < INT_MAX / 10)
            {
                rev = rev * 10 + x % 10;
                x /= 10;
            }
            else
            {
                return (false);
            }
        }
        cout << temp << " " << rev << endl;
        return (temp == rev);
    }
};