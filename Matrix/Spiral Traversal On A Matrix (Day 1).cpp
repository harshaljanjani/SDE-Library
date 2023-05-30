// key notes of errors:
// 1) very important (condition): "count < r * c"
// 2) possible mistake : while(startRow != endRow || startCol != endCol) seems infinitely more intuitive, but dry-run proves it's not the correct approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // function to return a list of integers denoting spiral traversal of matrix
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int startRow = 0, startCol = 0, endRow = r - 1, endCol = c - 1;
        vector<int> ans;
        int count = 0;
        while (count < r * c)
        {
            for (int i = startCol; i <= endCol && count < r * c; i++)
            {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for (int i = startRow; i <= endRow && count < r * c; i++)
            {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for (int i = endCol; i >= startCol && count < r * c; i--)
            {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for (int i = endRow; i >= startRow && count < r * c; i--)
            {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return (ans);
    }
};