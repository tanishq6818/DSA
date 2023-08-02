 // find the shortest path from (0,0) to (X,Y) in a 2D binary matrix, we can use Breadth-First Search (BFS) algorithm. 
// Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
// Note: You can only move left, right, up and down, and only through cells that contain 1.

// Example 1:

// Input:
// N=3, M=4
// A=[[1,0,0,0], 
//    [1,1,0,1],
//    [0,1,1,1]]
// X=2, Y=3 
// Output:
// 5
// Explanation:
// The shortest path is as follows:
// (0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
// Example 2:

// Input:
// N=3, M=4
// A=[[1,1,1,1],
//    [0,0,0,1],
//    [0,0,0,1]]
// X=0, Y=3
// Output:
// 3
// Explanation:
// The shortest path is as follows:
// (0,0)->(0,1)->(0,2)->(0,3).
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

int shortestDistance(int N, int M, vector<vector<int>>& A, int X, int Y) {
    // Check if the starting cell is blocked (0,0)
    if (A[0][0] == 0) {
        return -1;
    }

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            if (x == X && y == Y) {
                return steps;
            }

            for (auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && A[newX][newY] == 1 && !visited[newX][newY]) {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        steps++;
    }
    
    return -1; // No path found
}
