// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.

// Example 1

// Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.
// Example 2

// Input:
// X = efgh, Y = jghi
// Output: 6
// Explanation: Shortest Common Supersequence
// would be ejfghi which is of length 6 and
// has both the strings as its subsequences.
// Your Task:
// You don't have to take any input or print anything. Your task is to complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

// Expected Time Complexity: O(Length(X) * Length(Y)).
// Expected Auxiliary Space: O(Length(X) * Length(Y)).

// Constraints:
// 1<= |X|, |Y| <= 100

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    // Create a dp array to store the length of the shortest common supersequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If one of the strings is empty, the length of the supersequence is the length of the other string
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            // If the last characters of both strings match, reduce the problem to the subproblem without these characters
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            // If the last characters are different, consider both options and choose the minimum
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // The length of the shortest common supersequence is the sum of the lengths of X and Y minus the length of their common subsequence
    return m + n - dp[m][n];
}
