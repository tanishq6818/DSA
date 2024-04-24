You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.

Example 1:

Input:
x = 3, y = 0 
Output: 
1
Explanation: Path used was -  (3,0)  --> ( 2,0) --> (1,0) --> (0,0).We can see that there is no other path than this, so we return 1.
Example 2:

Input:
x = 3, y = 6
Output: 
84 
Explanation:
There are total 84 possible paths.
Your Task:
Since this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function ways() that takes integer x and y as parameters and returns the total number of paths from point(x,y) to the origin(0,0) % 1000000007.

Expected Time Complexity: O(x*y).
Expected Auxiliary Space: O(x*y).

Constraints:
0 ≤ x, y ≤ 500

  const int MOD = 1000000007;

int ways(int x, int y) {
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

    // Base case: There's only one way to reach any point on the x-axis or y-axis.
    for (int i = 0; i <= x; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= y; ++j) {
        dp[0][j] = 1;
    }

    // Fill the dp table
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[x][y];
}
