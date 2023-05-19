#include <bits/stdc++.h>
using namespace std;
// idea: if the number of set bits is 1
// edge case: if the number is less than or equal to 0, it is not a power of 2 and should not be considered in the logic
// alternative solution (by using an axiom/observation): return (((n) & (n-1)) == 0);
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // deal with edge case
        if (n <= 0)
        {
            return (false);
        }
        // main logic
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        if (count == 1)
        {
            return (true);
        }
        return (false);
    }
};