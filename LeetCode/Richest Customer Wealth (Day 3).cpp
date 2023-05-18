#include <bits/stdc++.h>
using namespace std;
// STL function used: accumulate(element.begin(), element.end(), 0) => (iter_start, iter_end, initial_sum)
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max_sum = INT_MIN, N = accounts.size(), sum, element;
        for (int i = 0; i < N; i++)
        {
            vector<int> element = accounts[i];
            sum = accumulate(element.begin(), element.end(), 0);
            max_sum = max(max_sum, sum);
        }
        return (max_sum);
    }
};