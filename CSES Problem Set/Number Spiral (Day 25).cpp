#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll answer(ll x, ll y)
{
    // when the max is even, the max element is to the left (column 1)
    // when the max is odd, the max element is to the right (row 1)
    ll mx = max(y, x); // find the parity of the L-shape matrix
    if (mx % 2 == 0)
    {
        if (y == 1)
        {
            return mx * mx;
        }
        else if (x < mx)
        {
            // if we knew the value at (mx, mx-x)
            return answer(mx, mx) - (mx - x); // reach principal diagonal first
        }
        else if (x == mx)
        {
            return mx * mx - (y - 1);
        }
    }
    // if mx is odd
    else
    {
        if (x == 1)
        {
            return mx * mx;
        }
        else if (y < mx)
        {
            return answer(mx, mx) - (mx - y);
        }
        else if (y == mx)
        {
            return mx * mx - (x - 1);
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll y, x;
        cin >> x >> y;
        cout << answer(x, y) << "\n";
    }
}
