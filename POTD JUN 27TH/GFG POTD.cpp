A Toeplitz (or diagonal-constant) matrix is a matrix in which each descending diagonal from left to right is constant, i.e., all elements in a diagonal are the same. Given a rectangular matrix mat, your task is to complete the function isToeplitz which returns true if the matrix is Toeplitz otherwise, it returns false.

Examples:

Input:
mat = [[6, 7, 8],
       [4, 6, 7],
       [1, 4, 6]]
Output: true
Explanation: The test case represents a 3x3 matrix
 6 7 8 
 4 6 7 
 1 4 6
Output will be true, as values in all downward diagonals from left to right contain the same elements.
Input: 
mat = [[1,2,3],
       [4,5,6]]
Output: false
Explanation: Matrix of order 2x3 will be 1 2 3 4 5 6 Output: false as values in all diagonals are not the same.
Constraints:
1<=mat.size,mat[0].size<=40
0<=mat[i][j]<=100

Expected time complexity: O(n*m)
Expected space complexity: O(1)

   bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        // Check all descending diagonals starting from top-left to bottom-left
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (mat[i][j] != mat[i-1][j-1]) {
                    return false;
                }
            }
        }
        
        // If all descending diagonals are checked and passed, return true
        return true;
    }
