Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
Note: Answer can be very large, so, ouput will be answer modulo 109+7.

Example 1:

Input: 
s = "gfg"
Output: 
7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
Example 2:

Input: 
s = "ggg"
Output: 
4
Explanation: 
The four distinct subsequences are "", "g", "gg", "ggg".
Your task:
You do not need to read any input or print anything. The task is to complete the function distinctSubsequences(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets 

const int MOD = 1000000007;

int distinctSubsequences(string s) {
    int n = s.length();
    
    // Initialize a dp array to store the number of distinct subsequences
    vector<int> dp(n + 1, 0);
    
    // An empty subsequence is always present
    dp[0] = 1;
    
    // Create a map to store the last index of each character
    unordered_map<char, int> lastIndex;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD; // Doubling the count by either including or excluding the current character
        
        // If the current character has occurred before, subtract the count of subsequences that end at the previous occurrence
        if (lastIndex.find(s[i - 1]) != lastIndex.end()) {
            int prevIndex = lastIndex[s[i - 1]];
            dp[i] = (dp[i] - dp[prevIndex - 1] + MOD) % MOD;
        }
        
        lastIndex[s[i - 1]] = i; // Update the last index of the current character
    }
    
    // Subtract 1 to exclude the empty subsequence
    return (dp[n] + MOD) % MOD;
}
