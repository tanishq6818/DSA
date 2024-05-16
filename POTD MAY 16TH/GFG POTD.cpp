Given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n - 1 edges and is rooted at node 1. Your task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each tree is divisible by 2.

Example 1:

Input: 
n = 10
edges = {{2,1},{3,1},{4,3},{5,2},{6,1},{7,2},{8,6},{9,8},{10,8}}
Output:
2
Explanation:
Original tree:

   
After removing edge 1-3 and 1-6, each remaining component consists of even number of nodes. 


Example 2:

Input: 
n = 4
edges = {{2,1},{4,2},{1,3}}
Output:
1
Explanation:
After removing 2-1, each remaining component consists of even number of nodes. 
Your Task:
You don't need to read or print anyhting. Your task is to complete the function minimumEdgeRemove() which takes n and edges as input parameters and returns the maximum number of edges that need to be removed from the given tree.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= n <= 105
edges.length == n - 1
1 <= edges[i][0], edges[i][1] <= n

  class Solution {
public:
    int ans = 0;

    //Function to perform depth-first search and count the number of edges to be removed.
    int dfs(int v, vector<bool>&vis, vector<vector<int>>&adj){
        int cnt = 0;
        int res = 0;
        //Marking vertex v as visited.
        vis[v] = true;
        //Iterating over the adjacent vertices of v.
        for(auto u: adj[v]){
            //If u is not visited, recursively calling dfs on u.
            if(!vis[u]){
                res = dfs(u, vis, adj);
                //If the result from dfs is even, incrementing the answer by 1.
                if(res%2 == 0) ans++;
                else cnt += res;
            }
        }
        //Returning the total count of edges to be removed from the subtree rooted at v.
        return cnt + 1;
    }

    //Function to find the minimum number of edges to be removed to make the graph disconnected.
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        //Creating a adjacency list representation of the graph.
        vector<vector<int>>adj(n);
        //Creating a visited array to keep track of visited vertices.
        vector<bool>vis(n, false);
        //Filling the adjacency list representation.
        for(auto i: edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        //Calling dfs on the root vertex (0).
        dfs(0, vis, adj);
        //Returning the minimum number of edges to be removed to make the graph disconnected.
        return ans;
    }
};
