#include <bits/stdc++.h>
using namespace std;
// cyclic rotation of an array by one position:
// idea: 1) save the value of the last element in a temporary variable *high*
// 2) shift each element (starting from the index *arr.size() - 2* down to index 0) by one place to the right
// 3) assign the value of the first element as *high*

void rotate(int arr[], int n)
{
    int high = arr[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = high;
}