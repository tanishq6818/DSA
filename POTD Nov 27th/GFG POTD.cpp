// Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

// Note: Solve the problem using disjoint set union (DSU).

// Example 1:

// Input: 

// Output: 1
// Explanation: There is a cycle between 0->2->4->0
// Example 2:

// Input: 

// Output: 0
// Explanation: The graph doesn't contain any cycle
// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function detectCycle() which takes number of vertices in the graph denoting as V and adjacency list adj and returns 1 if graph contains any cycle otherwise returns 0.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ 104

class Solution 
{
    public:
    //Function to find root of a node.
	int find_set(int v, vector<int>&parent)
	{
	    //calling function recursively to get parent node.
		if(v != parent[v])
		v = find_set(parent[v], parent);
		return v;
	}
	
	//Function to merge two nodes a and b.
	void unionn(int x, int y, vector<int>&parent, vector<int>&rank)
	{
		x = find_set(x, parent);
		y = find_set(y, parent);
		if(rank[x] < rank[y])
			swap(x, y);
		parent[y] = x;
		rank[x] += rank[y];
	}
	
	//Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
		vector<int>parent(V);
		vector<int>rank(V,0);
		
		for(int i = 0; i < V; i++){
			parent[i] = i;
			rank[i] = 1;
		}
		
		map<pair<int,int>,int>mp;
		for(int u = 0; u < V; u++)
		{
		    //iterating through all edges of graph, finding subset of
            //both vertices of every edge, if both subsets are
            //same, then there is cycle in graph.
			for(auto v: adj[u])
			{
				if(mp.find({u,v}) != mp.end() or mp.find({v,u}) != mp.end())
				    continue;
				mp[{v,u}] = 1;
				int x = find_set(u, parent);
				int y = find_set(v, parent);
				if(x == y)
				{
				    //returning 1 if there is a cycle.
					return 1;
				}
				unionn(u, v, parent, rank);
			}
		}
		return 0;
	}
};
