#include <bits/stdc++.h>
using namespace std;
// idea: sort an array against a pivot element (usually chosen as the first or the last element of the array)
void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot, t, i, j;
        pivot = arr[low];
        // initialization of integer pointers
        i = low + 1;
        j = high;
        while (true)
        {
            // while (i < j) does not work (the last pair is not swapped)
            // (pivot > a[i] && i <= high) and (pivot < a[j] && j >= low)
            // idea: to bring all the elements lesser than arr[pivot] to the left of it, and the elements greater than or equal to arr[pivot], to the right of it
            // find index of first element from the left greater than pivot
            while (arr[i] < pivot && i <= high)
            {
                i++;
            }
            // find index of first element from the right lesser than pivot
            while (arr[j] > pivot && j >= low)
            {
                j--;
            }
            if (i < j)
                swap(arr[i], arr[j]);
            // if i > j => break
            else
                break;
        }
        // order of re-assignment: (low <- j <- pivot)
        arr[low] = arr[j];
        arr[j] = pivot;
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}

// driver function
int main(void)
{
    int i, len;
    cout << "Enter The Array Length" << endl;
    cin >> len;
    int *arr = (int *)malloc(len * sizeof(int));
    for (i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, len - 1);
    cout << "The Array After Sorting By Quick Sort Is" << endl;
    for (i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}