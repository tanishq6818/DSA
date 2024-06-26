Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

Examples:

Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input: 
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(1)

Constraints:
1 <= matrix.size, matrix[0].size <= 100
  int findCoverage(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int coverageSum = 0;
    
    // Directions for left, right, up, down
    vector<int> dirX = {0, 0, -1, 1};
    vector<int> dirY = {-1, 1, 0, 0};
    
    // Traverse the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                // Calculate coverage for this zero
                int coverage = 0;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dirX[d];
                    int nj = j + dirY[d];
                    // Check bounds and count adjacent ones
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && matrix[ni][nj] == 1) {
                        coverage++;
                    }
                }
                // Add the coverage to the sum
                coverageSum += coverage;
            }
        }
    }
    
    return coverageSum;
}
