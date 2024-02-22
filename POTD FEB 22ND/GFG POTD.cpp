// Given two strings s and t of length n and m respectively. Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.

// Example 1:

// Input:
// s = "banana" , t = "ban"
// Output: 
// 3
// Explanation: 
// There are 3 sub-sequences:[ban], [ba n], [b an].
// Example 2:

// Input:
// s = "geeksforgeeks" , t = "ge"
// Output: 
// 6
// Explanation: 
// There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].
// Your Task:
// You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument s and t and returns the count of the sub-sequences modulo 109 + 7.

// Expected Time Complexity: O(n*m).
// Expected Auxiliary Space: O(n*m).

// Constraints:
// 1 ≤ n,m ≤ 1000

const int MOD = 1000000007;

int subsequenceCount(string s, string t) {
    int n = s.length();
    int m = t.length();

    // dp[i][j] will store the count of subsequences of t[0...j-1] in s[0...i-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Empty string is a subsequence of every string
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // If current characters match, consider both options: include or exclude current character of s
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            } else {
                // If characters do not match, consider excluding current character of s
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}
