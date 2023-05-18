#include <bits/stdc++.h>
using namespace std;
// idea: eliminate the extra 1's in the negation of n, using bit-masking
// bitwise-& eliminates all the excess 1's at the beginning of the negation, and only retains the last 'n' bits, where n = number of bits in the integer n = floor(log2(n)) + 1;
// extra: find the binary value of integer n -> binary += (n&1) * pow(10, i++);
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        // number of bits in an integer = floor(log2(n)) + 1;
        if (n == 0)
        {
            return (1);
        }
        int temp = ~n;
        int mask = 0;
        while (n != 0)
        {
            n = n >> 1;
            mask = (mask << 1) | 1;
        }
        return (mask & temp);
        // extra : code to find the binary value of the integer n
        int bin = 0, i = 0;
        while (n != 0)
        {
            bin = bin + (n & 1) * pow(10, i);
            n = n >> 1;
            i++;
        }
    }
};