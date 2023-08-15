// inefficient (slightly)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    string s;
    cin >> s;
    ll n = s.length();
    ll max = -1;
    for (auto i = 0; i < n; i++)
    {
        auto j = i;
        for (; j < n;)
        {
            if (s[i] == s[j])
            {
                if (j - i + 1 > max)
                {
                    if (j == n)
                    {
                        max = j - i;
                    }
                    else
                    {
                        max = j - i + 1;
                    }
                }
                j++;
            }
            else
            {
                break;
            }
        }
    }
    cout << max;
}

// efficiency increased
int main(void)
{
    string s;
    cin >> s;
    int ans = 1, c = 0;
    char l = 'A';
    for (char d : s)
    {
        if (d == l)
        {
            c++;
            ans = max(c, ans);
        }
        else
        {
            l = d;
            c = 1;
        }
    }
    cout << ans;
}