#include <bits/stdc++.h>
using namespace std;
// flood fill algorithm
// question link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
// idea: 1) follow bfs (level-wise traversal/equi-distant traversal) or dfs(recursive call stack)
// 2) initial call: dfs(sr,sc) (sr = starting row, sc = starting column)
// 3) create a copy of the matrix (never alter the original data => principle followed in SWE)
/*
 example matrix
 [1, 1, 1]
 [2, 2, 0]
 [2, 2, 2]
*/
// dfs(2,0) -> dfs(1,0) -> dfs(1,1) -> dfs(2,1) -> dfs(2,2) // end of call
//          -> dfs(2,1) // end of call

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int initColor)
    {
        // set image[sr][sc] to newColor
        ans[row][col] = newColor;
        int n = image.size();    // number of rows
        int m = image[0].size(); // number of columns
        // check for 4-directional neighbors
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, newColor, initColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initColor = image[sr][sc];
        // make a copy
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, newColor, initColor);
        return ans;
    }
};

// algorithm analysis
// time complexity: worst case (all the nodes have to be re-colored/every single node is of initColor within the matrix) = O(N * M)
// space complexity: O(N * M)(external matrix) + O(N * N)(recursive call stack space)