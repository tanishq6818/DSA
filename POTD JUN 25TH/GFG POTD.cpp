You are given an integer k and matrix mat. Return a matrix where it is rotated Left k times.

Examples:

Input: k=1, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
1 2 3
4 5 6
7 8 9
Explanation: Rotate the matrix by one
1 2 3       2 3 1
4 5 6  =>  5 6 4
7 8 9       8 9 7
Input: k=2, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
3 1 2
6 4 5
9 7 8
Explanation: After rotating the matrix looks like
1 2 3       2 3 1       3 1 2
4 5 6  =>  5 6 4  =>   6 4 5
7 8 9       8 9 7       9 7 8
Expected Time Complexity: O(n*m)
Expected Auxillary Space: O(n*m)

Constraints:
1<= mat.size, mat[0].size, mat[i][j] <=1000
1<=k<=10000

vector<vector<int>> rotateMatrix(int k, vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    // Effective number of rotations (since rotating by cols is the same)
    k = k % cols;
    
    vector<vector<int>> rotated(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Calculate the new position after left rotation
            int new_col = (j - k + cols) % cols;
            rotated[i][new_col] = mat[i][j];
        }
    }
    
    return rotated;
}
