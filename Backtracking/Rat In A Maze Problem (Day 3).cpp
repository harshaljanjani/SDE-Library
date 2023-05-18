#include <bits/stdc++.h>
using namespace std;
/*
 idea: two functions:
 A) isSafe(): checks if the node is safe to visit or not based on the following conditons:
 1) the value of i and j must be in the range of 0 to n-1
 2) the value of m[i][j] = 1 (which means the node is not an obstacle, but is infact traversable)
 3) the node has not been visited yet (!visited[i][j] or visited[i][j] == 0)
 B) pathfinder(): the main logic of pathfinding, with backtracking, a recursive function call structure and a base conditon as suited to solve the problem.
*/
class Solution
{
private:
    bool isSafe(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n)
    {
        if ((i >= 0 && i <= n - 1) && (j >= 0 && j <= n - 1) && !visited[i][j] && m[i][j])
        {
            return (true);
        }
        return (false);
    }
    void pathfinder(vector<string> &ans, vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n, string &element)
    {
        // base conditon
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(element);
            return;
        }
        visited[i][j] = 1; // backtrack - (ii)
        // recursive calls
        // down
        if (isSafe(m, visited, i + 1, j, n))
        {
            element.push_back('D');
            pathfinder(ans, m, visited, i + 1, j, n, element);
            element.pop_back(); // backtrack - (i)
        }
        // up
        if (isSafe(m, visited, i - 1, j, n))
        {
            element.push_back('U');
            pathfinder(ans, m, visited, i - 1, j, n, element);
            element.pop_back(); // backtrack - (i)
        }
        // left
        if (isSafe(m, visited, i, j - 1, n))
        {
            element.push_back('L');
            pathfinder(ans, m, visited, i, j - 1, n, element);
            element.pop_back(); // backtrack - (i)
        }
        // right
        if (isSafe(m, visited, i, j + 1, n))
        {
            element.push_back('R');
            pathfinder(ans, m, visited, i, j + 1, n, element);
            element.pop_back(); // backtrack - (i)
        }
        visited[i][j] = 0; // backtrack - (ii)
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string element;
        // check for base condition:
        if (!m[0][0])
        {
            return (ans);
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        pathfinder(ans, m, visited, 0, 0, n, element);
        return (ans);
    }
};