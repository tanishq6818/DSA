You are given a matrix of dimensions n x m. The task is to perform boundary traversal on the matrix in a clockwise manner.

Example 1:

Input:
n = 4, m = 4
matrix[][] = {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15,16}}
Output: 1 2 3 4 8 12 16 15 14 13 9 5
Explanation:
The matrix is:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
The boundary traversal is:
1 2 3 4 8 12 16 15 14 13 9 5
Example 2:

Input:
n = 3, m = 4
matrrix[][] = {{12, 11, 10, 9},
         {8, 7, 6, 5},
         {4, 3, 2, 1}}
Output: 12 11 10 9 5 1 2 3 4 8
Your Task:
Complete the function boundaryTraversal() that takes matrix, n and m as input parameters and returns the list of integers that form the boundary traversal of the matrix in a clockwise manner.

Expected Time Complexity: O(N + M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n, m<= 1000
0 <= matrixi <= 1000


  vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m) {
    vector<int> result;

    if (n == 1) {  // If there is only one row
        for (int j = 0; j < m; j++) {
            result.push_back(matrix[0][j]);
        }
    } else if (m == 1) {  // If there is only one column
        for (int i = 0; i < n; i++) {
            result.push_back(matrix[i][0]);
        }
    } else {  // For matrices with more than one row and column
        // Traverse the first row
        for (int j = 0; j < m; j++) {
            result.push_back(matrix[0][j]);
        }
        // Traverse the last column
        for (int i = 1; i < n; i++) {
            result.push_back(matrix[i][m - 1]);
        }
        // Traverse the last row (if there are multiple rows)
        if (n > 1) {
            for (int j = m - 2; j >= 0; j--) {
                result.push_back(matrix[n - 1][j]);
            }
        }
        // Traverse the first column (if there are multiple columns)
        if (m > 1) {
            for (int i = n - 2; i >= 1; i--) {
                result.push_back(matrix[i][0]);
            }
        }
    }

    return result;
}

