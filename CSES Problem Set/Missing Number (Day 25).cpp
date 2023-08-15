#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    ll n;
    ll s = 0, a;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;
        s += a;
    }
    cout << (n * (n + 1)) / 2 - s;
}