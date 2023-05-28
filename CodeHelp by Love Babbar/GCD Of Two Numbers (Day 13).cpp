#include <bits/stdc++.h>
using namespace std;
// idea:
// 1) if (a > b), subtract b from a (a = a - b)
// 2) if (b > a), subtract a from b (b = b - a)
// 3) repeat steps 1 and 2 until a is equal to b (while a != b)
// edge case condition: if either of the numbers are 0, then return the other number
// 4) return a, this is the GCD of the two numbers (any of a or b can be returned, since at the end of the iteration of the while loop, a == b)

int gcd(int a, int b)
{
    if (a == 0)
    {
        return (b);
    }
    if (b == 0)
    {
        return (a);
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return (a);
}