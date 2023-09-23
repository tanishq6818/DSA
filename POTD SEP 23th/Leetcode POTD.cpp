// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

int longestStrChain(vector<string>& words) {
    int n = words.size();
    
    // Sort the words by their length to optimize the DP solution
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    
    unordered_map<string, int> dp; // Stores the longest chain ending with each word
    
    int longestChain = 1; // Initialize with a minimum chain length of 1
    
    for (string word : words) {
        int currChain = 1; // Initialize the current chain length for the current word
        
        // Try removing one character from the current word and check if the shorter word is in dp
        for (int i = 0; i < word.length(); i++) {
            string shorterWord = word.substr(0, i) + word.substr(i + 1);
            if (dp.find(shorterWord) != dp.end()) {
                currChain = max(currChain, dp[shorterWord] + 1);
            }
        }
        
        dp[word] = currChain; // Store the current chain length for the word
        
        longestChain = max(longestChain, currChain); // Update the longest chain
    }
    
    return longestChain;
}
