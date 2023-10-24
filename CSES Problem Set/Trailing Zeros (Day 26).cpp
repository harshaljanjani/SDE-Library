#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    for (ll i = 10; i <= n; i *= 10)
    {
        ans += n / i;
    }
    cout << ans;
}