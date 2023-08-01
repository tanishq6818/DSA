void dfsUtil(int vertex, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Add the current vertex to the result vector
    result.push_back(vertex);

    // Recursively visit all the adjacent vertices that are not visited yet
    for (int adjacent : adj[vertex]) {
        if (!visited[adjacent]) {
            dfsUtil(adjacent, adj, visited, result);
        }
    }
}

// Function to perform DFS on the entire graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> result;
    vector<bool> visited(V, false);

    // Start DFS from each unvisited vertex
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited, result);
        }
    }

    return result;
}
