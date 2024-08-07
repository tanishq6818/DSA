Given two integers n, m and a 2D matrix mat of dimensions nxm, the task is to find the maximum sum of an hourglass.
An hourglass is defined as a part of the matrix with the following form:



Return -1 if any hourglass is not found.

Example 1:

Input:
n = 3, m = 3
mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
Output:
35
Explanation:
There is only one hour glass which is
1 2 3
  5
7 8 9   and its sum is 35.
Example 2:

Input:
n = 2, m = 3
mat = [[1, 2, 3],
       [4, 5, 6]]
Output:
-1
Explanation:
There are no hour glasses in this matrix.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the two integers n, m, and the 2D matrix mat as input parameters and returns the maximum sum of an hourglass in the matrix. If there are no hourglasses, it returns -1.

Expected Time Complexity: O(n*m)
Expected Auxillary Space: O(1)

Constraints:
1 <= n <= 150
3 <= m <= 150
0 <= mat[i][j] <= 106

  int findMaxSum(int n, int m, vector<vector<int>> mat) {
    // Initialize maximum sum as negative infinity
    int maxSum = INT_MIN;

    // Iterate through the matrix to find hourglasses
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            // Calculate sum of current hourglass
            int currentSum = mat[i][j] + mat[i][j+1] + mat[i][j+2] +
                             mat[i+1][j+1] +
                             mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
            // Update maxSum if necessary
            maxSum = max(maxSum, currentSum);
        }
    }

    // Return -1 if no hourglass was found, otherwise return maxSum
    return maxSum == INT_MIN ? -1 : maxSum;
}
