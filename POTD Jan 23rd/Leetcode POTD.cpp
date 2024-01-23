You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.

  public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<std::string> validSubsequences;
        backtrack(arr, 0, "", validSubsequences);
        
        int maxLength = 0;
        for (const std::string& subsequence : validSubsequences) {
            maxLength = std::max(maxLength, static_cast<int>(subsequence.size()));
        }
        
        return maxLength;
    }
    
private:
    void backtrack(const std::vector<std::string>& arr, int index, std::string current, std::vector<std::string>& validSubsequences) {
        if (isUnique(current)) {
            validSubsequences.push_back(current);
        } else {
            return;
        }
        
        for (int i = index; i < arr.size(); ++i) {
            backtrack(arr, i + 1, current + arr[i], validSubsequences);
        }
    }
    
    bool isUnique(const std::string& s) {
        std::unordered_set<char> charSet;
        for (char c : s) {
            if (charSet.count(c) > 0) {
                return false; // Not unique
            }
            charSet.insert(c);
        }
        return true;
    }
