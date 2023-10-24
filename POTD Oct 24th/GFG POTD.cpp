// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".
// Example 2:

// Input: str = "aaabba"
// Output: 1
// Explaination: The substrings after 1
// partitioning are "aa" and "abba".

// Your Task:
// You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.


// Expected Time Complexity: O(n*n) [n is the length of the string str]
// Expected Auxiliary Space: O(n*n)


// Constraints:
// 1 ≤ length of str ≤ 500

class Solution {
public:
    int palindromicPartition(string str) {
        int n = str.length();
        
        // Create a table to store if a substring from i to j is a palindrome.
        bool isPalindrome[n][n];
        
        // Initialize the table with false values.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                isPalindrome[i][j] = false;
            }
        }
        
        // All substrings of length 1 are palindromes.
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        
        // Check for palindromes of length 2 or more.
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (str[i] == str[j] && (len == 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        
        // Create a table to store the minimum cuts needed.
        int minCuts[n];
        
        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                minCuts[i] = 0;
            } else {
                minCuts[i] = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i] && minCuts[j] + 1 < minCuts[i]) {
                        minCuts[i] = minCuts[j] + 1;
                    }
                }
            }
        }
        
        return minCuts[n - 1];
    }
};
