You are presented with an undirected connected graph consisting of n vertices and connections between them represented by an adjacency matrix. Your objective is to determine whether it is possible to start traversing from a node, x, and return to it after traversing all the vertices at least once, using each edge exactly once.

Example 1:

Input: 
paths = 0 1 1 1 1
        1 0 0 1 0
        1 0 0 1 0
        1 1 1 0 1
        1 0 0 1 0
Output: 1
Explanation: 
One can visit the vertices in the following way:
1->3->4->5->1->4->2->1 (assuming 1-based indexing)
Here all the vertices has been visited and all
paths are used exactly once.
Example 2:

Input: 
paths = 0 1 1 0
        1 0 1 1
        1 1 0 0
        0 1 0 0
Output: 0
Explanation: 
There exists no such vertex from which all the 
vertices could be visited and all edges are used 
exactly once.
Your Task:
You don't need to read or print anything. Your task is to complete the function isPossible() which takes adjacency matrix paths as an input parameter and returns 1 if it is possible to start traversing from a node, x, and come back to it after traversing all the vertices at least once, using each edge exactly once.

 Expected Time Complexity: O(n2)
Expected Space Compelxity: O(1)

Constraints:
1 <= n <= 100
0 <= paths[i][j] <= 1
Note: paths[i][j] = 0 where i == j or there exists no edge between i and j. paths[i][j] = 1 means there is a path between i to j.

  bool isConnected(vector<vector<int>>& paths, vector<bool>& visited, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++count;
            if (count > 1) return false; // More than one connected component
            dfs(paths, visited, i, n);
        }
    }
    return true;
}

void dfs(vector<vector<int>>& paths, vector<bool>& visited, int u, int n) {
    visited[u] = true;
    for (int v = 0; v < n; ++v) {
        if (paths[u][v] && !visited[v]) {
            dfs(paths, visited, v, n);
        }
    }
}

bool hasEvenDegrees(vector<vector<int>>& paths, int n) {
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            degree += paths[i][j];
        }
        if (degree % 2 != 0) return false; // Vertex with odd degree
    }
    return true;
}

int isPossible(vector<vector<int>>& paths) {
    int n = paths.size();

    // Check if the graph is connected
    vector<bool> visited(n, false);
    if (!isConnected(paths, visited, n)) {
        return 0; // Not connected
    }

    // Check if all vertices have even degrees
    if (!hasEvenDegrees(paths, n)) {
        return 0; // Not all vertices have even degrees
    }

    return 1; // Graph has an Eulerian circuit
}
