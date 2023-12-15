// There are N points on the road, you can step ahead by 1 or 2 . If you start from a point 0, and can only move from point i to point i+1 after taking a step of length one, find the number of ways you can reach at point N. 

// Example 1:

// Input: 
// N = 4
// Output: 
// 5
// Explanation: Three ways to reach at 4th
// point. They are {1, 1, 1, 1}, {1, 1, 2},
// {1, 2, 1} {2, 1, 1}, {2, 2}.

// Example 2:

// Input: N = 5
// Output: 8
// Explanation: Three ways to reach at 5th
// point. They are {1, 1, 1, 1, 1},
// {1, 1, 1, 2}, {1, 1, 2, 1}, {1, 2, 1, 1},
// {2, 1, 1, 1}{1, 2, 2}, {2, 1, 2}, {2, 2, 1}
// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function nthPoint() which takes N as input parameter and returns the total number of ways modulo 109 + 7 to reach at Nth point.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)

// Constraints:
// 1 ≤ N ≤ 105

int nthPoint(int N) {
    // Initialize a vector to store the number of ways to reach each point
    vector<int> dp(N + 1, 0);

    // Base case: There is one way to reach the starting point
    dp[0] = 1;

    // Fill the dp vector using dynamic programming
    for (int i = 1; i <= N; ++i) {
        // The number of ways to reach the current point is the sum of
        // the number of ways to reach the previous two points
        dp[i] = (dp[i - 1] + dp[i - 2]) % (1000000007);
    }

    // Return the number of ways to reach the Nth point
    return dp[N];
}
