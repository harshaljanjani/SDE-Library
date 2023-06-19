#include <bits/stdc++.h>
using namespace std;
// question link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// idea: 1) store the mapping of digits (array indexes) to their corresponding letters(strings) in a string array
// 2) programming paradigm => backtracking and recursion
// 3) approach => include/exclude approach with (int index)
class Solution
{
private:
    void combination(vector<string> &ans, string element, string digits, string mapping[8], int index)
    {
        // base case for recursion
        if (index >= digits.size())
        {
            ans.push_back(element);
            return;
        }
        int digit = digits[index] - '2'; // convert (char) to (int) (mapping is only done from 2 to 9 (inclusive))
        // check the alphabets mapped to the current digit from the mapping[] array
        string mapped = mapping[digit];
        // mapped.length() = 3 (for 2, 3, 4, 5, 6 and 8) or 4 (for 7 and 9);
        for (int i = 0; i < mapped.length(); i++)
        {
            element.push_back(mapped[i]);
            // move to the next index (index + 1)
            combination(ans, element, digits, mapping, index + 1);
            element.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans; // result vector of all permutations
        // edge case optimization: if the digits string is empty
        if (digits.length() == 0)
        {
            return ans;
        }
        string element; // each permutation would be stored here
        int index = 0;  // which index in the string are we currently at (with each recursive call, index = index + 1)
        string mapping[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combination(ans, element, digits, mapping, index);
        return ans;
    }
};