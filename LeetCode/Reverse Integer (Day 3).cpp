#include <bits/stdc++.h>
using namespace std;

// naive approach (fails edge cases):
/* idea:
1) reversed_x = reversed_x * 10 (existing digits shifted by one place to the left) + x % 10 (last digit);
2) x /= 10 (divide the number by 10 - floor divide)
*/
class Solution
{
public:
    int reverse(int x)
    {
        int reversed_x = 0;
        while (x != 0)
        {
            reversed_x = reversed_x * 10 + x % 10;
            x /= 10;
        }
        return (reversed_x);
    }
};

// corrected approach (corrected for edge cases):
// trying to answer the question: what happens if the number becomes greater than 2^31 - 1 or lesser than - 2^31?
/* idea:
1) reversed_x = reversed_x * 10 (existing digits shifted by one place to the left) + x % 10 (last digit);
2) x /= 10 (divide the number by 10 - floor divide)
3) modification: check if the number reversed_x is less than INT_MIN / 10 or greater than INT_MAX / 10 (cannot multiply reversed_x by 10 to compare with INT_MIN directly, since (reversed_x * 10) would not be able to be stored within the int datatype)
*/
class Solution
{
public:
    int reverse(int x)
    {
        int reversed_x = 0;
        while (x != 0)
        {
            // modification when compare to naive approach (cater to the edge cases)
            if (reversed_x > INT_MAX / 10 || reversed_x < INT_MIN / 10)
            {
                return (0);
            }
            reversed_x = reversed_x * 10 + x % 10;
            x /= 10;
        }
        return (reversed_x);
    }
};