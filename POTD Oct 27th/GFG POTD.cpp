// Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
// Note: The order of characters in the string should be maintained.

// Example 1:

// Input: 
// S = "aebcbda"
// Output: 
// 2
// Explanation: 
// Remove characters 'e' and 'd'.
// Example 2:

// Input: 
// S = "geeksforgeeks"
// Output: 
// 8
// Explanation: 
// One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

// Expected Time Complexity: O(|S|2)
// Expected Auxiliary Space: O(|S|2)

// Constraints:
// 1 ≤ |S| ≤ 103

 int minimumNumberOfDeletions(string S) {
        int n = S.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;  // Single characters are palindromes by themselves.
        }

        for (int cl = 2; cl <= n; cl++) {
            for (int i = 0; i < n - cl + 1; i++) {
                int j = i + cl - 1;
                if (S[i] == S[j] && cl == 2) {
                    dp[i][j] = 2; // Two identical characters form a palindrome.
                } else if (S[i] == S[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int longestPalindromicSubsequence = dp[0][n - 1];
        int deletions = n - longestPalindromicSubsequence;

        return deletions;
    }
