#include <bits/stdc++.h>
using namespace std;
// greedy approach:
// note: a) often provides sub-optimal solutions, when DP provides the global optimal solution by looking at the problem from a "broader perspective"
// b) all matroid problems have a greedy solution
// c) has to possess optimal substructure, greedy choice property, feasibility, optimality (local) and irrevocability (no backtracking)
// d) choose greedy over DP if you have the choice

// idea: 1) initialize a variable gap = 0. gap is the difference between the indices of the last element, and the index of the *maximum element we can reach by jumping according to the given constraints, before we can no longer jump towards the last element*
// 2) start iterating from the last but one element of the array, towards the first element
// 3) if the value of nums[i] <= gap, then increment gap by 1 (gap++)
// 4) else, set gap to 0 (gap = 0)
// 5) our requirement, when (i == 0), is that (gap == 0) as well. if not, return false
// example test case:
// input 1: [2, 3, 1, 1, 4]
// output: true, jump 1 step from index 0 to 1, then 3 steps to the last index.
// input 2: [3, 2, 1, 0, 4]
// output: false, you will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int gap = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] <= gap)
            {
                gap++;
            }
            else
            {
                gap = 0;
            }
        }
        return gap == 0;
    }
};