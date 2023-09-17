// You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

// Example 1:


// Input: graph = [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]
// Example 2:


// Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]
 

// Constraints:

// n == graph.length
// 1 <= n <= 12
// 0 <= graph[i].length < n
// graph[i] does not contain i.
// If graph[a] contains b, then graph[b] contains a.
// The input graph is always connected.

int shortestPathLength(std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    
    // Initialize the queue for BFS
    std::queue<std::pair<int, int>> q;
    
    // Initialize a set to track visited nodes and the bitmask for visited nodes
    std::unordered_set<std::string> visited;
    
    // Add all nodes to the queue as starting points
    for (int i = 0; i < n; i++) {
        q.push({i, 1 << i});
        visited.insert(std::to_string(i) + "-" + std::to_string(1 << i));
    }
    
    int step = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int node = q.front().first;
            int bitmask = q.front().second;
            q.pop();
            
            // If all nodes are visited, return the steps taken
            if (bitmask == (1 << n) - 1) {
                return step;
            }
            
            // Explore neighbors
            for (int neighbor : graph[node]) {
                int newBitmask = bitmask | (1 << neighbor);
                std::string key = std::to_string(neighbor) + "-" + std::to_string(newBitmask);
                
                // If this state hasn't been visited, add it to the queue
                if (visited.find(key) == visited.end()) {
                    q.push({neighbor, newBitmask});
                    visited.insert(key);
                }
            }
        }
        step++;
    }
    
    return -1; // Return -1 if there is no path that visits every node
}
