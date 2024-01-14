// Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

// Example 1:

// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"
// Example 2:

// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
// Example 3:

// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"
 

// Constraints:

// 1 <= word1.length, word2.length <= 105
// word1 and word2 contain only lowercase English letters.

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) {
        return false;
    }

    unordered_map<char, int> freq1, freq2;
    unordered_set<char> chars1, chars2;

    for (char ch : word1) {
        freq1[ch]++;
        chars1.insert(ch);
    }

    for (char ch : word2) {
        freq2[ch]++;
        chars2.insert(ch);
    }

    // Check if the sets of characters are the same
    if (chars1 != chars2) {
        return false;
    }

    // Check if the frequencies of characters are the same
    unordered_map<int, int> freqCount1, freqCount2;

    for (auto& entry : freq1) {
        freqCount1[entry.second]++;
    }

    for (auto& entry : freq2) {
        freqCount2[entry.second]++;
    }

    return freqCount1 == freqCount2;
}
