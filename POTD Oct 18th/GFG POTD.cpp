// A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Example 1:

// Input:


// Output:
// 2 4 5 6
// Explanation:
// The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no 
// outgoing edges from either of them. 
// Every path starting at nodes 2, 4, 5, and 6 all 
// lead to either node 5 or 6.
// Example 2:

// Input:


// Output:
// 3
// Explanation:
// Only node 3 is a terminal node, and every path 
// starting at node 3 leads to node 3.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

// Expected Time Complexity: O(V + E)

// Expected Space Complexity: O(V)

// Constraints:

// 1 <= V <= 104
// 0 <= E <= 104
// The graph won't contain self loops.
// Each node in the graph has a distinct value in the range 0 to V - 1.

class Solution {
public:
    // Perform a depth-first search starting from the given node.
    // Return true if the node is part of a cycle, otherwise return false.
    bool dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& safeNodes) {
        if (visited[node] == 1) return true;  // This node is part of a cycle.
        if (visited[node] == 2) return false; // This node has already been determined to be safe.
        
        visited[node] = 1; // Mark the node as visited in current DFS traversal.
        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, visited, safeNodes)) return true; // If a cycle is found, return true.
        }
        visited[node] = 2; // Mark the node as safe.
        safeNodes.push_back(node);
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V, 0); // 0: unvisited, 1: visited in current DFS, 2: safe node
        vector<int> safeNodes;
        
        for (int i = 0; i < V; ++i) {
            if (dfs(i, adj, visited, safeNodes)) continue; // If part of a cycle, skip to the next node.
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
