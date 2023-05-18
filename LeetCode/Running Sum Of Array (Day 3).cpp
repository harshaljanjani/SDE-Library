// naive approach:
/* idea:
1) calculate the sum of all the elements to the left of the i-th element
2) add it to the element at the i-th position
3) reassign the sum_l to the i-th element
*/
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int sum_l = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += sum_l; // add sum_l to the current element
            sum_l = nums[i];  // reassign sum_l to the new cumulative sum (current element)
        }
        return (nums);
    }
};

// optimized approach:
// idea: add the previous element to the current element with each iteration
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        return (nums);
    }
};