Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.


Example 1:

Input: str = "abcdecba"
n = 8, k = 1
Output: 1
Explaination: By removing 'd' or 'e' 
we can make it a palindrome.

Example 2:

Input: str = "abcdefcba"
n = 9, k = 1
Output: 0
Explaination: By removing a single 
character we cannot make it a palindrome.

Your Task:
You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n, and k as input parameters and returns 1 if str is a K-palindrome else returns 0.


Expected Time Complexity: O(n*n)
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ n, k ≤ 103

int kPalindrome(string str, int n, int k) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP table
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // Check if the minimum deletions needed are less than or equal to k
    return dp[0][n - 1] <= k ? 1 : 0;
}
