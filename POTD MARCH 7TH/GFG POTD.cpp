// Given a string s of length n, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. Return the longest non-overlapping substring. Return "-1" if no such string exists.

// Note: Multiple Answers are possible but you have to return the substring whose first occurrence is earlier.

// For Example: "abhihiab", here both "ab" and "hi" are possible answers. But you will have to return "ab" because it's first occurrence appears before the first occurrence of "hi".

// Example 1:

// Input:
// n = 9
// s = "acdcdacdc"
// Output:
// "acdc"
// Explanation:
// The string "acdc" is the longest Substring of s which is repeating but not overlapping.
// Example 2:

// Input:
// n = 7
// s = "heheheh"
// Output:
// "heh"
// Explanation:
// The string "heh" is the longest Substring of s which is repeating but not overlapping.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestSubstring() which takes an Integer n and a string s as input and returns the answer.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= n <= 103

string longestSubstring(string s, int n) {
    // Create a 2D DP array to store the length of the longest repeating non-overlapping substring
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Variables to store the length of the longest repeating non-overlapping substring and its ending position
    int maxLength = 0, endPos = 0;

    // Iterate through the string to fill the DP array
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // If characters match and the previous characters also match
            if (s[i - 1] == s[j - 1] && dp[i - 1][j - 1] < j - i) {
                // Update the DP array
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // If the current substring is longer than the previous longest substring
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i - 1;  // Update the ending position
                }
            } else {
                dp[i][j] = 0;  // Reset if characters don't match or overlap
            }
        }
    }

    // If no repeating non-overlapping substring is found, return "-1"
    if (maxLength == 0) {
        return "-1";
    }

    // Return the longest repeating non-overlapping substring
    return s.substr(endPos - maxLength + 1, maxLength);
}
