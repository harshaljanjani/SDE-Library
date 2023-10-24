#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// question link (daily challenge, 24th October 2023): https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// idea (basis: bfs for binary search trees): 1) queue<int> q -> the nodes that are currently undergoing the visit process
// 2) key: to realize that the row size is the length of the queue, at each iteration of the loop
// 3) we maintain the maxVal for each row, and continue to traverse the left and right nodes to the current node until the queue hasn't been rendered empty
// 4) append the maxVal as chosen, to the result vector

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // utility function: bfs, not recursive
    vector<int> bfs(TreeNode *root)
    {
        vector<int> result;
        // edge case
        if (!root)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int rowSize = q.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < rowSize; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                maxVal = max(maxVal, current->val);
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }
            result.push_back(maxVal);
        }
        return result;
    }

public:
    vector<int> largestValues(TreeNode *root)
    {
        return bfs(root);
    }
};