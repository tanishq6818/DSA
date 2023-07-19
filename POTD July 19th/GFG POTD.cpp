int longestPalinSubseq(string A) {
        //code here
        int n = A.length();

        // Create a 2D DP array to store the length of the longest palindromic subsequence
        // dp[i][j] will store the length of the longest palindromic subsequence from index i to j in string A.
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        // All substrings of length 1 are palindromic with a length of 1.
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
    
        // Loop through the string to fill the dp array.
        // Start from the second-to-last row and go upwards.
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // If characters at positions i and j are the same, then we add 2 to the longest subsequence
                // because these two characters contribute to a palindromic subsequence.
                if (A[i] == A[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // If characters at positions i and j are different, we consider two cases:
                    // 1. Exclude character at position i and find the longest subsequence in the substring [i+1, j]
                    // 2. Exclude character at position j and find the longest subsequence in the substring [i, j-1]
                    // Then, we take the maximum of these two cases.
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    
        // The answer will be stored in dp[0][n-1], representing the longest palindromic subsequence from index 0 to n-1.
        return dp[0][n - 1];
    }
