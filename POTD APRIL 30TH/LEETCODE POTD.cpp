// A wonderful string is a string where at most one letter appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
// Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: word = "aba"
// Output: 4
// Explanation: The four wonderful substrings are underlined below:
// - "aba" -> "a"
// - "aba" -> "b"
// - "aba" -> "a"
// - "aba" -> "aba"
// Example 2:

// Input: word = "aabb"
// Output: 9
// Explanation: The nine wonderful substrings are underlined below:
// - "aabb" -> "a"
// - "aabb" -> "aa"
// - "aabb" -> "aab"
// - "aabb" -> "aabb"
// - "aabb" -> "a"
// - "aabb" -> "abb"
// - "aabb" -> "b"
// - "aabb" -> "bb"
// - "aabb" -> "b"
// Example 3:

// Input: word = "he"
// Output: 2
// Explanation: The two wonderful substrings are underlined below:
// - "he" -> "h"
// - "he" -> "e"
 

// Constraints:

// 1 <= word.length <= 105
// word consists of lowercase English letters from 'a' to 'j'.

long long wonderfulSubstrings(std::string word) {
    std::unordered_map<long long, long long> freq;
    freq[0] = 1;

    long long mask = 0;
    long long res = 0;
    for (char c : word) {
        int bit = c - 'a';
        mask ^= (1LL << bit);

        if (freq.find(mask) != freq.end()) {
            res += freq[mask];
            freq[mask]++;
        } else {
            freq[mask] = 1;
        }

        for (int odd_c = 0; odd_c < 10; odd_c++) {
            if (freq.find(mask ^ (1LL << odd_c)) != freq.end()) {
                res += freq[mask ^ (1LL << odd_c)];
            }
        }
    }
    return res;
}
