#include <bits/stdc++.h>
using namespace std;
// source: https://youtu.be/Qzf1a--rhp8
/*
 example graph
 adjacency list:
 1 -> {2,3}
 2 -> {1,5,6}
 3 -> {1,4,7}
 4 -> {3,8}
 5 -> {2}
 6 -> {2}
 7 -> {3,8}
 8 -> {4,7}
*/

// idea
// 1) which programming paradigm goes to the depth, solves it and comes back? -> recursion
// 2) check if its 1-based or 0-based indexing

// initial configuration
// 1) a visited array (1-based, so size = N = 8)
// so initial configuration for n = 8 and startingNode = [1] would be:
// visited array (set visited[startingNode] = true): [0,1,0,0,0,0,0,0]

// pseudocode
/*
 -> dfs(node){
    vis[node] = 1;
    dfslist.add(node);
    for(auto it: adj[node]){
        // only go into the depth if it is not visited
        // main point: goes into the depth, and only then moves on to the next recursive call
        if(!vis[it]){
            dfs(it);
        }
    }
 }
 -> recursive call stack example:
 dfs(1) -> dfs(2) -> dfs(5) // no unvisited neighbors
                  -> dfs(6) // no unvisited neighbors
        -> dfs(3) -> dfs(4) -> dfs(8) // no neighbors
                            -> dfs(7) // // no neighbors
                  -> dfs(7) // // no unvisited neighbors
*/

// connected undirected graph (0-based indexing graph)
class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &dfslist)
    {
        vis[node] = 1;
        dfslist.push_back(node);
        // to traverse all its neighbors
        for (auto it : adj[node])
        {
            // go in depth if the nodes have not been visited yet
            if (!vis[it])
            {
                dfs(it, adj, vis, dfslist);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int start = 0;
        vector<int> dfslist;
        dfs(start, adj, vis, dfslist);
        return dfslist;
    }
}

// algorithm analysis
// space complexity: O(N)(for visited nodes in the dfslist) + O(N)(visited array) + O(N)(recursion stack space in the worst case scenario (left/right skewed graph)) = O(N)
// time complexity:
/*
    function structure
    f(){ => called for a single node, once
        for(... neighbors){ => for an undirected graph = summation(degree of each node in the graph) = 2 * E (number of edges in the graph)
            f(); O(N) -> for each node, called once
        }
    }
*/
// therefore, final time complexity for an undirected graph: O(N) + O(2 * E); for a directed graph, it'll be (E) not (2 * E);