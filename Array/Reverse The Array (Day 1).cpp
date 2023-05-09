#include <bits/stdc++.h>
using namespace std;
// utility functions
void inputArray(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}
void displayArray(int *arr, int N)
{
    cout << "The Reversed Array Is: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}
// main logic
void reverseArray(int *arr, int N)
{
    int low = 0, high = N - 1;
    while (low < high)
    {
        int t = arr[low];
        arr[low] = arr[high];
        arr[high] = t;
        low++;
        high--;
    }
}
// driver function
int main(void)
{
    int *arr;
    int N;
    cout << "Enter The Number Of Elements In The Array" << endl;
    cin >> N;
    arr = (int *)malloc(N * sizeof(int));
    inputArray(arr, N);
    reverseArray(arr, N);
    displayArray(arr, N);
}