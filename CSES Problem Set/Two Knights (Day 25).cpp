#include <bits/stdc++.h>
using namespace std;
// use complementary counting (combinatorics)
// A: Number of ways of placing two knights
// B: Number of ways of placing two knights so that they attack each other
// Answer = A - B
#define ll long long
int main()
{
    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++)
    {
        ll a1 = k * k, a2 = a1 * (a1 - 1) / 2;
        // (total number of 2*3 rectangles + total number of 3*2 rectangles) * 2 (each gives two ways of placing the knights)
        // 2*((k-1)*(k-2)+(k-1)*(k-2)) = 4*(k-1)*(k-2)
        if (k > 2)
        {
            a2 -= 4 * (k - 1) * (k - 2);
        }
        cout << a2 << "\n";
    }
}
