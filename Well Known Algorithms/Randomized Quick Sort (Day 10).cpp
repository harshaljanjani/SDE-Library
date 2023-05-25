#include <bits/stdc++.h>
using namespace std;
// idea: 1) quick sort usually chooses a pivot element, and sorts the input list around that pivot element
// 2) randomization is done on the input list, so that the sorted input is jumbled again, which reduces the time complexity (this is not usually performed in randomized quick sort)
// 3 a) randomly choosing the pivot element: making the pivot element a random variable is the most frequently used method in randomized quick sort
// 3 b) here, even if the input is sorted, the pivot is chosen randomly so the worst case time complexity is avoided

// this function randomizes the complete array elements (attempt at removing any edge cases => when the input is sorted at the beginning)
void array_randomization(int *arr, int len)
{
    srand(time(NULL));
    for (int i = len - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

// this function returns the partition index (i.e. the *divide index* between the left and right halves)
int partitioning(int *arr, int l, int r)
{
    // idea: to bring all the elements lesser than arr[pivot] to the left of it, and the elements greater than or equal to arr[pivot], to the right of it
    // index = the index, which is the least index (in the left half) available for unique swapping
    int pivot = r, index = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    // so, the pivot comes at the divide index
    swap(arr[index], arr[pivot]);
    return index; // return the divide index
}

// this function is the main logic of the quick sort algorithm
void quicksort(int *arr, int l, int r)
{
    // 1) find the pivot using the partitioning(arr,l,r) function
    // 2) call quicksort(arr,l,r) recursively for the left and right halves until exhaustion of the length of each (l is not less than r)
    if (l < r)
    {
        int pivot = partitioning(arr, l, r);
        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, r);
    }
}

// driver function
int main(void)
{
    int i, len;
    cout << "Enter The Array Length" << endl;
    cin >> len;
    int arr[len];
    for (i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    array_randomization(arr, len);
    quicksort(arr, 0, len - 1);
    cout << "The Array After Sorting By Randomized Quick Sort Is" << endl;
    for (i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}