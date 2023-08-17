// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:


// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.


 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<std::vector<int>> result(m, std::vector<int>(n, INT_MAX));
        std::queue<std::pair<int, int>> queue;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    queue.push({i, j});
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!queue.empty()) {
            int row = queue.front().first;
            int col = queue.front().second;
            queue.pop();

            for (const auto& direction : directions) {
                int newRow = row + direction.first;
                int newCol = col + direction.second;
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (result[newRow][newCol] > result[row][col] + 1) {
                        result[newRow][newCol] = result[row][col] + 1;
                        queue.push({newRow, newCol});
                    }
                }
            }
        }

        return result;
    }
