#include <bits/stdc++.h>
using namespace std;
// idea: check if the last bit of the number is 1, increment the count value by 1 and right shift the number by 1
class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        while (N > 0)
        {
            if (N & 1)
            {
                count++;
            }
            N = N >> 1;
        }
        return (count);
    }
};