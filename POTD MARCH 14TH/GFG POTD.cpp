// Given a square matrix a of size n x n, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally you need to find the largest square within the grid where all its border cells are 'X'.

// Example 1:

// Input:
// n = 2
// a = [[X,X],
//      [X,X]]
// Output:
// 2
// Explanation:
// The largest square submatrix 
// surrounded by X is the whole 
// input matrix.
// Example 2:

// Input:
// n = 4
// a = [[X,X,X,O],
//      [X,O,X,X],
//      [X,X,X,O],
//      [X,O,X,X]]
// Output:
// 3
// Explanation:
// Here,the input represents following 
// matrix of size 4 x 4
// X X X O
// X O X X
// X X X O
// X O X X
// The square submatrix starting at 
// (0,0) and ending at (2,2) is the 
// largest submatrix surrounded by X.
// Therefore, size of that matrix would be 3.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function largestSubsquare() which takes the integer n and the matrix a as input parameters and returns the size of the largest subsquare surrounded by 'X'.

// Expected Time Complexity: O(n2)
// Expected Auxillary Space: O(n2)

// Constraints:
// 1 <= n <= 1000
// a[i][j] belongs to {'X','O'} 

int largestSubsquare(int n, vector<vector<char>> a) {
    // Initialize an auxiliary matrix to store sizes of largest square subgrids
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int maxSize = 0;

    // Fill the first row and first column of dp matrix with values from input matrix
    for (int i = 0; i < n; ++i) {
        dp[i][0] = (a[i][0] == 'X') ? 1 : 0;
        dp[0][i] = (a[0][i] == 'X') ? 1 : 0;
        maxSize = max(maxSize, dp[i][0]);
        maxSize = max(maxSize, dp[0][i]);
    }

    // Iterate through the rest of the matrix to fill dp using dynamic programming
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (a[i][j] == 'X') {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize;
}
