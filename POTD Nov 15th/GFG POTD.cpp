// Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences. If both the strings have equal count of distinct subsequence then return str1.

// Example 1:

// Input:
// str1 = "gfg", str2 = "ggg"
// Output: "gfg"
// Explanation: "gfg" have 7 distinct subsequences whereas "ggg" have 4 distinct subsequences. 
// Example 2:

// Input: str1 = "a", str2 = "b"
// Output: "a"
// Explanation: Both the strings have only 1 distinct subsequence. 
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function betterString() which takes str1 and str2 as input parameters and returns the better string.

// Expected Time Complexity: O( max( str1.length, str2.length ) )

// Expected Auxiliary Space: O( max( str1.length, str2.length ) )

// Constraints:
// 1 <= str1.lenght , str2.length <= 30

string betterString(string str1, string str2) {
    int mod = 1e9 + 7;
    
    int m = str1.length();
    int n = str2.length();
    
    // dp[i][j] represents the count of distinct subsequences of str1.substr(0, i) and str2.substr(0, j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                // Empty string has one subsequence, which is an empty string itself.
                dp[i][j] = 1;
            } else if (str1[i - 1] == str2[j - 1]) {
                // If the current characters are the same, we have two choices:
                // 1. Include the current characters in the subsequence, which is dp[i-1][j-1]
                // 2. Exclude either of the current characters and take the count from the previous row or column
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] + 1) % mod;
            } else {
                // If the current characters are different, we can simply choose to exclude one of them
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod) % mod;
            }
        }
    }
    
    // The result is the count of distinct subsequences of the entire strings.
    int result = dp[m][n];
    
    return (result > 0) ? str1 : str2;
}
