#include <bits/stdc++.h>
using namespace std;
// idea: use modified binary search, in the range 0 to n to find the square root
// valid ranges: [0, n/2+1] (factoring in test cases like sqrt(1))
// invalid ranges: [0, n-1] (edge case '1' failed to give correct output)
// use (long long int) for *mid, ans and square*, because *low and high* would always be in the range of the INT datatype

// algo: 1) if (mid*mid)>n, look in the left half i.e. high = mid-1
// 2) if (mid*mid)<n, look in the right half i.e. low = mid+1 and save the current mid in a variable *ans*
// 3) if no exact match for mid is found (mid*mid != n perfectly), return *ans* (closest floor integer to the square root)

class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0, high = x / 2 + 1;
        long long int square, ans = -1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            square = mid * mid;
            if (square == x)
            {
                return (mid);
            }
            else if (square < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return (ans);
    }
};