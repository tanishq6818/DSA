// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
// substrings
//  respectively, such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

 

// Example 1:


// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
// Since s3 can be obtained by interleaving s1 and s2, we return true.
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
// Example 3:

// Input: s1 = "", s2 = "", s3 = ""
// Output: true
 

// Constraints:

// 0 <= s1.length, s2.length <= 100
// 0 <= s3.length <= 200
// s1, s2, and s3 consist of lowercase English letters.
 
bool isInterleave(string s1, string s2, string s3) {
        int len_s1 = s1.length();
        int len_s2 = s2.length();
        int len_s3 = s3.length();
        
        if (len_s1 + len_s2 != len_s3) {
            return false;
        }
        
        vector<vector<bool>> dp(len_s1 + 1, vector<bool>(len_s2 + 1, false));
        
        // Base case: both strings are empty, so s3 is also empty
        dp[0][0] = true;
        
        // Initialize the first row (when s2 is empty)
        for (int i = 1; i <= len_s1; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        
        // Initialize the first column (when s1 is empty)
        for (int j = 1; j <= len_s2; ++j) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        
        // Fill the DP table
        for (int i = 1; i <= len_s1; ++i) {
            for (int j = 1; j <= len_s2; ++j) {
                // Check if the current character in s3 can be formed by interleaving
                // the characters from s1 and s2
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return dp[len_s1][len_s2];
    }
