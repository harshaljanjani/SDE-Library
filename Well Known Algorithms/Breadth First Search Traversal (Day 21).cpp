#include <bits/stdc++.h>
using namespace std;
// source: https://youtu.be/-tgVpUgsQ5k
/*
 example graph
         [[1]]
        /    \
      /       \
    [2]       [6]
   /   \     /   \
 [3]  [4]   [7] [9]
      /      \
    [5] ———— [8]
 adjacency list for the graph
 1 -> {2,6}
 2 -> {1,3,4}
 3 -> {2}
 4 -> {2,5}
 5 -> {4,8}
 6 -> {1,7,9}
 7 -> {6,8}
 8 -> {5,7}
 9 -> {6}
*/

// idea
// 1) could be 1-based or 0-based indexing
// 2) left to right / right to left => does not matter
// 3) very important: what if the starting node is not [1]? (for example [6]) => nodes at equivalent distances from the starting node are at the same level

// initial configuration
// 1) use a queue (FIFO), with startingNode as the first insertion, and a visited array (1-based, so 1 + n = 1 + 9 = 10)
// so initial configuration for n = 10 and startingNode = [1] would be:
// visited array (set visited[startingNode] = true): [0,1,0,0,0,0,0,0,0,0], and queue = [1]
// 4) take out whatever is in the queue, and print the data, and insert, from the adjacency list, its *unvisited* neighbors, and mark them as visited
// 5) repeat until the whole visited list is filled with true/1

class Solution
{
public:
    // function to return breadth first traversal of given graph for both directed and undirected graphs (adjacency list given => vector<int> adj[])
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        // take out everything from the queue until it's empty
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push(node);
            // check neighbor nodes
            for (auto it : adj[node])
            {
                // !vis[with index == (it)]
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
}

// algorithm analysis
// final space complexity: queue, visited array, bfs list -> [O(N)] (omit adjacency list)
// time complexity: 1) node goes once into the bfs, and for each node, it also runs on all its neighbors
// 2) therefore, it runs on *all its degrees* (number of neighboring nodes)
// thus, final time complexity: [O(N) + O(2E)] (not O(N * 2E))
// basically, it would have been O(N * 2E) if for each node, total number of adjacent nodes would be 2E; but in this case, in the *whole* undirected graph, the total degrees would be 2E, so it is added => total number of edges traversed