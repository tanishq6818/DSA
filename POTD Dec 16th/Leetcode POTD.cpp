// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

bool isAnagram(std::string s, std::string t) {
    // Check if the lengths of the strings are different
    if (s.length() != t.length()) {
        return false;
    }

    // Use unordered maps to store the frequency of characters in both strings
    std::unordered_map<char, int> frequencyS;
    std::unordered_map<char, int> frequencyT;

    // Count the frequency of characters in string s
    for (char c : s) {
        frequencyS[c]++;
    }

    // Count the frequency of characters in string t
    for (char c : t) {
        frequencyT[c]++;
    }

    // Compare the frequencies of characters in both strings
    for (const auto& pair : frequencyS) {
        char c = pair.first;
        if (frequencyT.find(c) == frequencyT.end() || frequencyT[c] != frequencyS[c]) {
            return false;
        }
    }

    return true;
}
