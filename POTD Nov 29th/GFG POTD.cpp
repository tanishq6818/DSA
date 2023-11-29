// An Eulerian Path is a path in graph that visits every edge exactly once and it starts and ends up at different indexes. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected acyclic graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

// Example 1:

// Input: 

// Output: 2
// Explanation: 
// Following is an eulerian circuit in the mentioned graph
// 1 -> 2 -> 0 -> 1
// Example 2:

// Input: 

// Output: 1
// Explanation: 
// Following is an eulerian circuit in the mentioned graph
// 1 -> 0 -> 2
// Your Task:
// You don't need to read or print anything. Your task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoted as V and an adjacency list of graph denoted as adj and returns 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, it returns 1, otherwise, it will return 0.

// Expected Time Complexity: O(V+E) where E is the number of edges in graph.
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 104
// 1 ≤ adj[i][j] ≤ V-1


class Solution {
public:
	// Utility function to perform depth-first search
	void dfsUtil(int u, vector<bool>&vis, vector<int>adj[]) {
		vis[u] = true;
		for(auto v: adj[u]){
			if(!vis[v])
				dfsUtil(v, vis, adj);
		}
	}

	// Function to check if the graph is connected
	bool isConnected(int V, vector<int>adj[]) {
		vector<bool>vis(V, false);
		int i;
		// Find the first non-empty vertex
		for(i = 0; i < V; i++){
			if(adj[i].size())
				break;
		}
		// Perform dfs on the first non-empty vertex
		dfsUtil(i, vis, adj);
		// Check if there are any vertices not visited but have edges
		for(i = 0; i < V; i++){
			if(!vis[i] and adj[i].size() > 0)
				return false;
		}
		return true;
	}

	// Function to check if the graph has an Euler circuit
	int isEulerCircuit(int V, vector<int>adj[]) {
		// Check if the graph is not connected
		if(!isConnected(V, adj))
			return 0; // Not Euler circuit
		int odd = 0;
		// Count the number of vertices with odd degree
		for(int i = 0; i < V; i++){
			if(adj[i].size() & 1)
				odd++;
		}
		// If there are more than two vertices with odd degree, not Euler circuit
		if(odd > 2)
			return 0; // Not Euler circuit
		// If there is one vertex with odd degree, semi-Euler circuit
		// If there are no vertices with odd degree, Euler circuit
		return odd ? 1 : 2;
	}
};
