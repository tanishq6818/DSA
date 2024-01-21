// Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest possible size of a vertex cover.

// Example 1:

// Input:
// N=5
// M=6
// edges[][]={{1,2}
//            {4, 1},
//            {2, 4},
//            {3, 4},
//            {5, 2},
//            {1, 3}}
// Output:
// 3
// Explanation:
// {2, 3, 4} forms a vertex cover
// with the smallest size.
// Example 2:

// Input:
// N=2
// M=1
// edges[][]={{1,2}} 
// Output: 
// 1 
// Explanation: 
// Include either node 1 or node 2
// in the vertex cover.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge list and an integer n for the number of nodes of the graph as input parameters and returns the size of the smallest possible vertex cover.

// Expected Time Complexity: O(M*2N)
// Expected Auxiliary Space: O(N2)

//  Constraints:
// 1 <= N <= 16
// 1 <= M <= N*(N-1)/2
// 1 <= edges[i][0], edges[i][1] <= N

class Solution{
    public:
    bool checkCover(int n, int k, int m, vector<vector<int>> &e) {
    	// Set has first 'k' bits high initially
    	int set = (1 << k) - 1;
    
    	int limit = (1 << n);
    
    	// To mark the edges covered in each subset of size 'k'.
    	bool visited[n + 1][n + 1];
    
    	while (set < limit) {
    		// Reset visited array for every subset of vertices.
    		memset(visited, 0, sizeof(visited));
    
    		// Set counter for number of edges covered from this subset of vertices to zero.
    		int cnt = 0;
    
    		// Selected vertex cover is the indices where 'set' has its bit high.
    		for (int j = 1, v = 1; j < limit; j = j << 1, v++) {
    			if (set & j) {
    				// Mark all edges emerging out of this vertex visited
    				for (int k = 1; k <= n; k++) {
    					if (e[v][k] && !visited[v][k]) {
    						visited[v][k] = 1;
    						visited[k][v] = 1;
    						cnt++;
    					}
    				}
    			}
    		}
    
    		// If the current subset covers all the edges
    		if (cnt == m) {
    			return true;
    		}
    
    		// Generate previous combination with k bits high set & -set = (1 << last bit high in set).
    		int c = set & -set;
    		int r = set + c;
    		set = (((r ^ set) >> 2) / c) | r;
    	}
    	return false;
    }

    int vertexCoverHelper(vector<vector<int>> e, int n, int m) {
    	// Binary search the answer.
    	int low = 1, high = n;
    
    	while (high > low) {
    		int mid = (low + high) >> 1;
    
    		if (checkCover(n, mid, m, e) == false) {
    			low = mid + 1;
    		}
    		else {
    			high = mid;
    		}
    	}
    	return low;
    }

int vertexCover(int n, vector<pair<int, int>> &edges) {

	int m = edges.size();

	vector<vector<int>> e(n + 1, vector<int>(n + 1, 0));

	// Push the adjacent nodes for each node.
	for (int i = 0; i < m; i++) {
		e[edges[i].first][edges[i].second] = 1;
		e[edges[i].second][edges[i].first] = 1;
	}
	return vertexCoverHelper(e, n, m);
    }
};
