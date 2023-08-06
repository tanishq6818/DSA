
// You are given a matrix 'MAT consisting of 'Nrows and 'M' columnsLet \{i, j\} represent the cell at the intersection of the ith row and the jth column. Each cell of the matrix MAT has either integer 0 or 1 For each cell in 'MAT, you have to find the Manhattan distance of the nearest cell from this cell that has the integer 0The nearest cell will be the cell having the minimum Manhattan distance from it Manhattan distance between two cells, ( p 1,q1) and \ p 2,q2\ is | p 1-p2|+|q1-q2| You should return a matrix consisting of 'N' rows and 'M' columns, where the cell (i, represents the Manhattan distance of the nearest cell from the cell (i, j) in 'MAT that has integer D

// Note

// 1. There is at least one cell having the integer in the given

// matrix. Sample Input 1:
// 2
// 1 1
// 0
// 2 3
// 0 1 1
// 0 1 1
// Sample Output 1:
// 0
// 0 1 2
// 0 1 2
// Explanation Of Sample Input 1:
// Test case 1:
// There is only one cell in the given matrix and that cell has integer 0, so the nearest cell from this cell having integer 0 is this cell itself. The Manhattan distance of the cell from itself will be 0.

// Test case 2:
// See the problem statement for an explanation.
// Sample Input 2:
// 2
// 3 3
// 1 1 1
// 1 1 1
// 1 1 0
// 3 4
// 1 1 0 1
// 1 1 1 1
// 0 1 1 0
// Sample Output 2:
// 4 3 2
// 2 3 1
// 2 1 0
// 2 1 0 1
// 1 2 1 1
// 0 1 1 0

vector<std::vector<int>> findNearestZero(std::vector<std::vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, INT_MAX));
    std::queue<std::pair<int, int>> q;
    
    // Enqueue all cells with value 0 and mark them as visited
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                result[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    // Define four directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // Perform BFS
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (result[nx][ny] > result[x][y] + 1) {
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return result;
}
