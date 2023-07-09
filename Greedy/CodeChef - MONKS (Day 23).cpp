#include <bits/stdc++.h>
#define ll long long
using namespace std;
// link: https://www.codechef.com/START49B/problems-old/MONKS
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll req = 0;
    for (int i = 0; i < n; i++)
    {
        req += (a[0] - a[i]);
    }
    if (req == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll cur = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        cur += a[i];
        req -= (a[i] - a[i + 1]) * (n - (i + 1));
        if (cur >= req)
        {
            cout << (++i) << endl;
            break;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}