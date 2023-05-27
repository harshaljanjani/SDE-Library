#include <bits/stdc++.h>
using namespace std;
// square root of a number with a given number of decimal points/precision using modified binary search
// function returns the closest integer (floor not ceil) to the square root the number
int sqrt_int(int X)
{
    int low = 0, high = X - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int square = mid * mid;
        if (square == x)
        {
            return mid;
        }
        else
        {
            if (square > mid)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }
    }
    return ans;
}

// function that adds the decimal part of length *precisionCount* to the integer square root
// idea: 1) initialize a variable *factor* to 1
// 2) in a loop, running for *precisionCount* number of times, divide the *factor* to be added to ans by 10 at each iteration
// 3) keep adding the *factor* to the ans, until ans * ans > target, within the above loop
// 4) move to the next iteration where *factor* has now been divided by 10, and repeat the step 3
double more_precision(int x, int precisionCount, int sqrt_int)
{
    int factor = 1;
    int ans = sqrt_int;
    for (int i = 0; i < precisionCount; i++)
    {
        factor /= 10;
        for (int j = ans; j * j < x; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main(void)
{
    long long int x;
    cout << "Number Whose Square Root Is To Be Calculated: ";
    cin >> x;
    int result = sqrt_int(x);
    int precisionCount;
    cout << "Precision Count: ";
    cin >> precisionCount;
    // syntax to set number of precision points: fixed << setprecision(precisionCount)
    cout << "The Square Root Of The Number With " << precisionCount << " Decimals Is: " << fixed << setprecision(precisionCount) << more_precision(x, precisionCount, result) << endl;
}