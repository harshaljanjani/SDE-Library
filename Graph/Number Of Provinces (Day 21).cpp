#include <bits/stdc++.h>
using namespace std;
// question link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

// task: find the number of provinces
// definition of a province: each node can visit every other node within the province
// idea: 1) if somehow we could figure out a representative node within each province, we could perform dfs traversal from these nodes from unique provinces to cover each node within the entire graph

// pseudocode
// visited array of size [n + 1] (even for 1-based indexing) => int vis[n+1] = {0};
/*
    for(int i = 1; i <= V; i++){
        if(!vis[i]){
            dfs(i); // dfs(1)->dfs(2)->dfs(3)
            // function dfs() makes sure each node is marked as visited as a part of the function call
            // very important: now, most importantly, this if statement would be executed as many times, as there are provinces within the graph! => main logic lies here
        }
    }
*/

class Solution
{
private:
    void dfs(int node, vector<int> &dfslist, vector<int> adjLs[], int *vis)
    {
        // mark the node as visited
        vis[node] = 1;
        dfslist.push_back(node);
        for (auto it : adjLs[node])
        {
            // if the node is not visited, perform dfs on it
            if (!vis[it])
            {
                dfs(it, dfslist, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // create our adjacency list from the adjacency matrix (usually adjancency list would be given, because of the minimal constraints in this case, an adjacency matrix was provided)
        vector<int> adjLs[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    // no self nodes
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        // main logic
        int vis[V] = {0};
        // mistake
        // int startNode = 0;
        // vis[startNode] = 1;
        vector<int> dfslist;
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, dfslist, adjLs, vis);
                count++;
            }
        }
        return count;
    }
};

// algorithm analysis
// space complexity: O(N)(visited array) + O(N)(recursion call stack space)
// time complexity: O(N) + O(V + 2E)
// outer loop: making a dfs() function call for all the N nodes (partial dfs for representative nodes) = O(N)
// inner loop: runs for the dfs() times (summation of partial dfs() calls for all the nodes) = O(V + 2E)