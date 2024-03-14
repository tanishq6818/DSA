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

class Solution {
  public:
    // Function to find the largest subsquare with 'X'
    int largestSubsquare(int n, vector<vector<char>> a) {
        int by_rows[n][n];
        int by_cols[n][n];

        // Calculate the number of 'X' horizontally for each row
        for (int i = 0; i < n; i++) {
            by_rows[i][0] = (a[i][0] == 'X' ? 1 : 0);
            for (int j = 1; j < n; j++) {
                if (a[i][j] == 'X') {
                    by_rows[i][j] = by_rows[i][j - 1] + 1;
                } else {
                    by_rows[i][j] = 0;
                }
            }
        }

        // Calculate the number of 'X' vertically for each column
        for (int j = 0; j < n; j++) {
            by_cols[0][j] = (a[0][j] == 'X' ? 1 : 0);
            for (int i = 1; i < n; i++) {
                if (a[i][j] == 'X') {
                    by_cols[i][j] = by_cols[i - 1][j] + 1;
                } else {
                    by_cols[i][j] = 0;
                }
            }
        }

        int res = 0;
        
        // Iterate over each cell from bottom right to top left
        for (int i = n - 1; i >= res; i--) {
            for (int j = n - 1; j >= res; j--) {
                int side = min(by_rows[i][j], by_cols[i][j]);
                while (side > res) {
                    // Check if a subsquare of size 'side' can be formed
                    if (by_rows[i - side + 1][j] >= side &&
                        by_cols[i][j - side + 1] >= side) {
                        res = side;
                    } else {
                        side--;
                    }
                }
            }
        }
        return res;
    }
};
