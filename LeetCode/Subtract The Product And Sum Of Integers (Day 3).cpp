#include <bits/stdc++.h>
using namespace std;
/* idea:
1) take the number's remainder with 10, to get the last digit
2) multiply with the product, and add to the sum, initialized at 1 and 0 respectively
3) return the difference as the result
*/
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0, product = 1;
        while (n > 0)
        {
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        return (product - sum);
    }
};