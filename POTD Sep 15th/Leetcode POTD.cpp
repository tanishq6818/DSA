// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:


// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
 

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> visited(n, false);  // To keep track of visited nodes
    vector<int> minDist(n, INT_MAX); // To store the minimum distance to each node
    int minCost = 0;

    // Start from the first point (you can choose any starting point)
    minDist[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1; // Node to be added to the MST
        // Find the unvisited node with the minimum distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        minCost += minDist[u];

        // Update the minimum distances to the unvisited neighbors of u
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                minDist[v] = min(minDist[v], cost);
            }
        }
    }

    return minCost;
}
