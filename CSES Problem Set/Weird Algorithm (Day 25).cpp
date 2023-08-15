// in-efficient (using recursion)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n)
{
    if (n % 2 == 0)
    {
        n /= 2;
    }
    else
    {
        n = n * 3 + 1;
    }
    if (n != 1)
    {
        cout << n << " ";
        solve(n);
    }
}
int main(void)
{
    ll n;
    cin >> n;
    cout << n << " ";
    solve(n);
    cout << 1;
}

// efficient solution
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    ll n;
    cin >> n;
    cout << n;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        cout << " " << n;
    }
}