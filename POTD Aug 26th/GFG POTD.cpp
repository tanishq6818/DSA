// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 
// 7
// Explanation: 
// "cbebebe" is the longest substring with 3 distinct characters.
// Example 2:

// Input: 
// S = "aaaa", K = 2
// Output: -1
// Explanation: 
// There's no substring with 2 distinct characters.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).

// Constraints:
// 1 ≤ |S| ≤ 105
// 1 ≤ K ≤ 26
// All characters are lowercase latin characters.

int longestKSubstr(string s, int k) {
    int n = s.size();
    if (n < k) {
        return -1; // Not enough characters for K distinct characters
    }
    
    int left = 0, maxLen = -1, distinctCount = 0;
    unordered_map<char, int> charFreq; // To keep track of character frequency in the window
    
    for (int right = 0; right < n; ++right) {
        charFreq[s[right]]++; // Include the character in the window
        if (charFreq[s[right]] == 1) {
            distinctCount++; // Increment distinct character count
        }
        
        // Shrink the window from the left if distinct characters exceed K
        while (distinctCount > k) {
            charFreq[s[left]]--;
            if (charFreq[s[left]] == 0) {
                distinctCount--;
            }
            left++;
        }
        
        // Update maximum length
        if (distinctCount == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }
    
    return maxLen;
}
