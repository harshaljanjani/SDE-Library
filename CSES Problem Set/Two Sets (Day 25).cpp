#include <bits/stdc++.h>
using namespace std;
#define ll long long
// total sum needs to be even
// if total sum is odd, there is no solution
int main()
{
    ll n;
    cin >> n;
    // if the total sum is odd, there is no solution
    if (n * (n + 1) / 2 % 2)
    {
        cout << "NO";
        return 0;
    }
    ll target = n * (n + 1) / 4; //(total_sum/2)
    vector<ll> a1;
    vector<ll> a2;
    for (ll i = n; i >= 1; i--)
    {
        if (target - i >= 0)
        {
            a1.push_back(i);
            target -= i;
        }
        else
        {
            a2.push_back(i);
        }
    }
    cout << "YES" << endl;
    cout << a1.size() << endl;
    for (size_t i = 0; i < a1.size(); i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl
         << a2.size() << endl;
    for (size_t i = 0; i < a2.size(); i++)
    {
        cout << a2[i] << " ";
    }
}
