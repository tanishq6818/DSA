// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

// to the cell diagonally up towards the right 
// to the right
// to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect until he can no longer move.

// Example 1:

// Input: n = 3, m = 3
// M = {{1, 3, 3},
//      {2, 1, 4},
//      {0, 6, 4}};
// Output: 12
// Explaination: 
// The path is {(1,0) -> (2,1) -> (2,2)}.

// Example 2:

// Input: n = 4, m = 4
// M = {{1, 3, 1, 5},
//      {2, 2, 4, 1},
//      {5, 0, 2, 3},
//      {0, 6, 1, 2}};
// Output: 16
// Explaination: 
// The path is {(2,0) -> (3,1) -> (2,2) 
// -> (2,3)} or {(2,0) -> (1,1) -> (1,2) 
// -> (0,3)}.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function maxGold() which takes the values n, m and the mine represented as a 2D array of positive integeres M as input parameters and returns the maximum amount of gold that can be collected.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// 0 ≤ M[i][j] ≤ 100

class Solution{
public:
    // Function to find the maximum amount of gold that can be collected
    // given the number of rows, columns, and a matrix representing the gold values
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // Define a 2D array dp to store the maximum amount of gold at each cell
        int dp[n+2][m+2];
        
        // Initialize all cells in dp to 0
        memset(dp, 0, sizeof(dp));
        
        // Iterate through each column and row
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                // Calculate the maximum amount of gold at the current cell
                dp[j][i] = M[j-1][i-1] + max(dp[j-1][i-1], max(dp[j][i-1], dp[j+1][i-1]));
            }
        }
        
        // Find the maximum amount of gold in the last column
        int ans = INT_MIN;
        for(int i = 0;i <= n;i++)
            ans = max(dp[i][m], ans);
        
        // Return the maximum amount of gold
        return ans;
    }
};
