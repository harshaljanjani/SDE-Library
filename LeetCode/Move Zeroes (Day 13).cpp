#include <bits/stdc++.h>
using namespace std;
// idea: A) if order is to be maintained:
// "exclude 0 and shift the rest left"
// here, the focus is on maintaining order of the non-zero elements, not shifting the zeroes to the right
// 1) maintain a pointer 'iter' signifying the lowest point of unique insertion in the array, initialized at 0
// 2) if the element being traversed in a loop from 1 to (n - 1) is not 0, then it is swapped with the iter element
// 3) however, if the element is 0, we just ignore it and move to the next element
// 4) automatically, all the zeroes *rise up* to the right/top

// idea: B) if the order is not to be maintained:
// "swap the current 0 and the highest point of unique swap"
// 1) initialize a pointer iter at 0 and high at nums.size() - 1
// 2) if nums[iter] is 0, swap(nums[iter], nums[high]), decrement high by 1 and increment iter by 1
// 3) repeat step two until iter > high (while iter <= high)

// solution to A) if the order is to be maintained
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int iter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[iter]);
                iter++;
            }
        }
    }
};

// solution to B) if maintaining the order is not necessary
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int iter = 0, high = nums.size() - 1;
        while (iter <= high)
        {
            if (nums[iter] == 0)
            {
                swap(nums[iter], nums[high]);
                high--;
            }
            iter++;
        }
    }
};

// most optimal solution to A) => snowball solution (dry run)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int snowBallSize = 0, t;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                snowBallSize++;
            }
            else
            {
                t = nums[i];
                nums[i] = 0;
                nums[i - snowBallSize] = t;
            }
        }
    }
};