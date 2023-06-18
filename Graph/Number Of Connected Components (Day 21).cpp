#include <bits/stdc++.h>
using namespace std;
// question link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
// source: https://youtu.be/muncqlKJrH0
// this problem is also called "number of islands"
/*
 example grid scenario
  0 [1   1]   0
  0 [1   1]   0
  0  0   1]   0
  0  0   0    0
 [1  1]  0   [1]
*/

// pseudocode
/*
    int count = 0;
    for(int row = 0; row<N; row++){
        for(int col = 0; col<M; col++){
            if(!vis[row][col]){
                bfs(row,col);
                count++;
            }
        }
    }
*/

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int m, int n)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            // marking the pair<int,int>
            q.pop();
            // traverse the neighbors and mark them in the visited
            // shortcut
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    // function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(row, col, vis, grid, m, n);
                }
            }
        }
        return count;
    }
};

// algorithm analysis
// space complexity: O(N ^ 2) (visited array) + O(N ^ 2)(queue space worst case time complexity)
// time complexity: bfs() called as many times as there are '1's in the grid => worst case (when all the grid cells are '1's) time complexity is O(N ^ 2) (because of the delrow and delcol loop)
// one case is ignored (when delrow = 0 and delcol = 0 (current node, which is marked as visited already), so it technically runs for (N ^ 2) - 1 times)