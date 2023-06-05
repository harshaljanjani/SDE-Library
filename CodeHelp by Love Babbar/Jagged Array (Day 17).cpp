#include <bits/stdc++.h>
using namespace std;
// idea: 1) a jagged array is an array where the 'i'th row has 'i + 1' columns/elements
// 2) implemented using custom dynamic memalloc: just a test to hone dynamic memory allocation and de-allocation syntax in C/C++

int main(void)
{
    // jagged array of m rows:
    int m;
    cin >> m;
    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[i + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i <= m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}