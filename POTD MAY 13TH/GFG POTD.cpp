Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is fully connected.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 

Example 1:

Input: 


e=3 
v=3
edges={{1, 2},{1, 3},{3, 2}}
Output: 
1
Explanation: 
We can see that there is only one component in the graph and in this component there is a edge between any two vertces.
Example 2:

Input:

e=5 
v=7
edges={{1, 2},{7, 2},{3, 5},{3, 4},{4, 5}}
Output: 
2
Explanation: 
We can see that there are 3 components in the graph. For 1-2-7 there is no edge between 1 to 7, so it is not a fully connected component. Rest 2 are individually fully connected component.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findNumberOfGoodComponent(), which takes an integer e and v and edges[][] as input parameters and returns an integer denoting the number of good components.

Expected Time Complexity: O(v+e)
Expected Auxiliary Space: O(depth of the graph)

Constraints:
1 <= edges[i][0], edges[i][1] <= v
1 ≤ v, e ≤ 104
All edges are unique


 void dfs(int v, int &vertices, int &edges, vector<vector<int>> &adj,
             vector<int> &visited) {
        visited[v] = 1;
        vertices++;             // Counting the number of vertices
        edges += adj[v].size(); // Counting the number of edges
        for (auto to : adj[v]) {
            if (!visited[to]) {
                dfs(to, vertices, edges, adj, visited);
            }
        }
    }

    // Function to find the number of "good" components
    int findNumberOfGoodComponent(int E, int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V + 1, vector<int>());

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans = 0;
        vector<int> visited(V + 1, 0);

        for (int i = 1; i <= V; i++) {
            // Check if the vertex is visited or not
            if (!visited[i]) {
                int vertices = 0, edges = 0;
                dfs(i, vertices, edges, adj, visited);
                // Checking if the component is "good"
                edges /= 2;
                if (edges == (vertices * (vertices - 1)) / 2)
                    ans++;
            }
        }
        return ans;
    }
