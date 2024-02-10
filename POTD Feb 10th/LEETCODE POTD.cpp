Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

  int countSubstrings(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;

    // All individual characters are palindromic
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        count++;
    }

    // Check for palindromic substrings of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            count++;
        }
    }

    // Check for palindromic substrings of length 3 or more
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
}
