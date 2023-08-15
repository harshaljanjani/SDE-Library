#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        k = 2 * k % ((int)1e9 + 7);
    }
    cout << k;
}