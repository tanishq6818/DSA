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

class Solution {
  public:
    int countSub(string str) {
        // Create an array to store index
        // of last
        vector<int> last(256, -1);

        // Length of input string
        int n = str.length();

        // dp[i] is going to store count of distinct
        // subsequences of length i.
        int dp[n + 1];

        // Empty substring has only one subsequence
        dp[0] = 1;

        // Traverse through all lengths from 1 to n.
        for (int i = 1; i <= n; i++) {
            // Number of subsequences with substring
            // str[0..i-1]
            dp[i] = 2 * dp[i - 1];

            // If current character has appeared
            // before, then remove all subsequences
            // ending with previous occurrence.
            if (last[str[i - 1]] != -1) dp[i] = dp[i] - dp[last[str[i - 1]]];

            // Mark occurrence of current character
            last[str[i - 1]] = (i - 1);
        }

        return dp[n];
    }
    string betterString(string str1, string str2) {
        int a = countSub(str1), b = countSub(str2);
        if (a < b) return str2;
        return str1;
    }
};
