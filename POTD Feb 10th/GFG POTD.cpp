// Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

// Example 1:

// Input:
// k = 12, n = 3
// arr[] = [[1, 2, 3], 
//        [4, 6, 5], 
//        [3, 2, 1]]
// Output: 
// 2
// Explanation: 
// There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
// Example 2:

// Input:
// k = 16, n = 3
// arr[] = [[1, 2, 3], 
//        [4, 6, 5], 
//        [9, 8, 7]]
// Output: 
// 0 
// Explanation: 
// There are no possible paths that lead to sum=16
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes n, k and 2D matrix arr[][] as input parameters and returns the number of possible paths.

// Expected Time Complexity: O(n*n*k)
// Expected Auxiliary Space: O(n*n*k)

// Constraints:

// 1 <= k < 100
// 1 <= n < 100
// 0 <= arrij <= 200

 long long numberOfPath(int n, int k, vector<vector<int>> arr){
          long long dp[n+1][n+1][k+1];
         for(int i=0; i<=n; i++){
             for(int j=0; j<=k; j++){
                 dp[i][n][j]=0;
                 dp[n][i][j]=0;
                 if(j-arr[n-1][n-1]==0){
                     dp[n-1][n-1][j]=1;
                 }else{
                     dp[n-1][n-1][j]=0;
                 }
             }
         }
         for(int i=n-1; i>=0; i--){
             for(int j=n-1; j>=0; j--){
                 if(i==n-1 && j==n-1){
                     continue;
                 }
                 for(int z=0; z<=k; z++){
                     if(z-arr[i][j]>=0){
                         dp[i][j][z]=dp[i][j+1][z-arr[i][j]]+dp[i+1][j][z-arr[i][j]];
                     }else{
                         dp[i][j][z]=0; 
                     }
                 }
             }
         }
         return dp[0][0][k];
    }
