// You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

// Note: The input graph can have self-loops and multiple edges.

// Example 1:

// Input:
// N = 4, M = 3
// G = [[0, 1], [1, 2], [1, 3]]
// Output: 
// 1
// Explanation: 
// Every node is reachable and the graph has no loops, so it is a tree
// Example 2:

// Input:
// N = 4, M = 3
// G = [[0, 1], [1, 2], [2, 0]]
// Output: 
// 0
// Explanation: 
// 3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 2*105
// 0 <= M <= 2*105

class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &edges) 
    {
        if(m!=n-1)
            return false;
            
        vector<bool>vis(n,false);
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int node=0;
        queue<int>q;
    
        vis[node]=true;
        int visited=1;
        q.push(node);
        
        while(q.size())
        {
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    visited++;
                    q.push(it);
                }
            }
        }
        return (visited==n);
    }
};
