// You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

// Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Example 1:

// Input:
// row = 3
// columns = 3 
// heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 
// 2
// Explaination: 
// The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.
// Example 2:

// Input:
// row = 2
// columns = 2 
// heights = [[7,7],[7,7]]
// Output: 
// 0
// Explaination: 
// Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Expected Time Complexity: O(rowsxcolumns)
// Expected Space Complexity: O(rowsxcolumns)

// Constraints:
// 1 <= rows, columns <= 100
// rows == heights.length
// columns == heights[i].length
// 0 <= heights[i][j] <= 106

int MinimumEffort(int rows, int columns,
                      vector<vector<int> >& heights)
    {
        // code here
        int N = heights.size(), M = heights[0].size();

        // priority queue containing pairs of cells and
        // their respective distance from the source cell in
        // the form {diff, {row of cell, col of cell}}
        priority_queue<
            pair<int, pair<int, int> >,
            vector<pair<int, pair<int, int> > >,
            greater<pair<int, pair<int, int> > > >
            pq;

        // distance matrix with initially all the cells
        // marked as unvisited
        vector<vector<int> > d(N, vector<int>(M, 1e9));
        // distance for source cell (0,0) is 0
        d[0][0] = 0;
        pq.push({ 0, { 0, 0 } });

        // array to traverse in all four directions
        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };

        // Iterate through the matrix by popping the
        // elements out of the queue and pushing whenever a
        // shorter distance to a cell is found
        while (!pq.empty()) {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            // return the current value of difference (which
            // will be min) if we reach the destination
            if (r == N - 1 && c == M - 1)
                return diff;
            for (int i = 0; i < 4; i++) {
                // r-1, c
                // r, c+1
                // r-1, c
                // r, c-1
                int nx = dx[i] + r;
                int ny = dy[i] + c;

                // checking validity of the cell
                if (nx >= 0 && nx < N && ny >= 0
                    && ny < M) {
                    // effort can be calculated as the max
                    // value of differences between the
                    // values of the node and its adjacent
                    // nodes
                    int nf = max(abs(heights[r][c]
                                     - heights[nx][ny]),
                                 diff);

                    // if the calculated effort is less than
                    // the prev value update as we need the
                    // min effort
                    if (nf < d[nx][ny]) {
                        d[nx][ny] = nf;
                        pq.push({ nf, { nx, ny } });
                    }
                }
            }
        }
        // if unreachable
        return -1;
    }
