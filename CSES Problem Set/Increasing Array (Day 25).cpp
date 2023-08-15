#include <bits/stdc++.h>
using namespace std;
#define ll long long
// initial idea
int main(void)
{
    int N;
    cin >> N;
    int max_index = 0;
    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    // global max index
    for (int i = 1; i < N; i++)
    {
        if (arr[max_index] < arr[i])
        {
            max_index = i;
        }
    }
    // to the right min element
    int minToTheRight = max_index;
    for (int i = max_index; i < N; i++)
    {
        if (arr[minToTheRight] > arr[i])
        {
            minToTheRight = i;
        }
    }
    cout << arr[max_index] - arr[minToTheRight];
}

// reworked idea
int main(void)
{
    ll N;
    cin >> N;
    ll ans = 0;
    ll mx = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        mx = max(mx, x);
        ans += mx - x;
    }
    cout << ans;
}