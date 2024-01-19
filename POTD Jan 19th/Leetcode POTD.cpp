// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Create a copy of the matrix to store intermediate results
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    // Initialize the first row of dp with the values from the matrix
    for (int i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i];
    }

    // Iterate through each row starting from the second row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Calculate the minimum falling path sum for the current position
            dp[i][j] = matrix[i][j] + min({dp[i - 1][max(0, j - 1)], dp[i - 1][j], dp[i - 1][min(n - 1, j + 1)]});
        }
    }

    // Find the minimum value in the last row of dp, which represents the minimum falling path sum
    int result = *min_element(dp[n - 1].begin(), dp[n - 1].end());

    return result;
}
