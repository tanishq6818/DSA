Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: n = 2, m = 2
mat = [[1, 1], 
       [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: n = 2, m = 2
mat = [[0, 0], 
       [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
0 ≤ mat[i][j] ≤ 1 

  int maxSquare(int n, int m, vector<vector<int>> mat) {
    // Edge case: empty matrix
    if (n == 0 || m == 0) return 0;
    
    // Initialize dp array with all zeros
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int max_side_length = 0;
    
    // Fill the dp table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0) {
                // First row or first column
                dp[i][j] = mat[i][j];
            } else if (mat[i][j] == 1) {
                // Check the neighbors
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
            // Update the maximum side length
            max_side_length = max(max_side_length, dp[i][j]);
        }
    }
    
    return max_side_length;
}
