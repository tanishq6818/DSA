Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to a set for O(1) lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> results;
        string currentSentence;
        // Start the backtracking process
        backtrack(s, wordSet, currentSentence, results, 0);
        return results;
    }

private:
    void backtrack(const string& s, const unordered_set<string>& wordSet,
                   string& currentSentence, vector<string>& results,
                   int startIndex) {
        // If we've reached the end of the string, add the current sentence to
        // results
        if (startIndex == s.length()) {
            results.push_back(currentSentence);
            return;
        }

        // Iterate over possible end indices
        for (int endIndex = startIndex + 1; endIndex <= s.length();
             ++endIndex) {
            string word = s.substr(startIndex, endIndex - startIndex);
            // If the word is in the set, proceed with backtracking
            if (wordSet.find(word) != wordSet.end()) {
                string originalSentence = currentSentence;
                if (!currentSentence.empty()) currentSentence += " ";
                currentSentence += word;
                // Recursively call backtrack with the new end index
                backtrack(s, wordSet, currentSentence, results, endIndex);
                // Reset currentSentence to its original state
                currentSentence = originalSentence;
            }
        }
    }
};
