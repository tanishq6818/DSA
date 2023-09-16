// A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

// Example 1:

// Input:
// N = 1
// Output: 1
// Example 2:

// Input:
// N = 4
// Output: 7
// Explanation:Below are the 7 ways to reach
// 4
// 1 step + 1 step + 1 step + 1 step
// 1 step + 2 step + 1 step
// 2 step + 1 step + 1 step
// 1 step + 1 step + 2 step
// 2 step + 2 step
// 3 step + 1 step
// 1 step + 3 step
// Your Task:
// Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 105

long long countWays(int n)
{
    const int MOD = 1000000007;
    
    // Create an array to store the number of ways to reach each step
    long long dp[n + 1];
    
    // Initialize dp[0] and dp[1] to 1 because there's one way to reach step 0 and 1.
    dp[0] = 1;
    dp[1] = 1;
    
    // Calculate dp[i] for i = 2 to n
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        if (i >= 3) {
            dp[i] = (dp[i] + dp[i - 3]) % MOD;
        }
    }
    
    // The answer is stored in dp[n]
    return dp[n];
}
