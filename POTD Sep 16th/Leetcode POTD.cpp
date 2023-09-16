// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example 1:



// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:



// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:


// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
 

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106


// Function to check if there exists a path with effort <= mid using BFS
bool isPathPossible(vector<vector<int>>& heights, int mid) {
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (const auto& dir : dirs) {
            int newR = r + dir[0];
            int newC = c + dir[1];
            
            if (newR >= 0 && newR < rows && newC >= 0 && newC < cols &&
                !visited[newR][newC] && abs(heights[newR][newC] - heights[r][c]) <= mid) {
                q.push({newR, newC});
                visited[newR][newC] = true;
            }
        }
    }
    
    return visited[rows - 1][cols - 1];
}

int minimumEffortPath(vector<vector<int>>& heights) {
    int left = 0;
    int right = 1e6; // The maximum possible effort
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (isPathPossible(heights, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
