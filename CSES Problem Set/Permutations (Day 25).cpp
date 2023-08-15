#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    // edge cases
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    // split pattern into odds and evens
    // evens (2 4 1 3)
    if (n % 2 == 0)
    {
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for (int i = 1; i < n; i += 2)
        {
            cout << i << " ";
        }
    }
    // odds (4 2 5 3 1)
    else
    {
        for (int i = n - 1; i >= 2; i -= 2)
        {
            cout << i << " ";
        }
        for (int i = n; i >= 1; i -= 2)
        {
            cout << i << " ";
        }
    }
}
