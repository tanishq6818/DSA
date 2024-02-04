// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq, windowFreq;
        
        // Count the frequency of each character in t
        for (char c : t) {
            tFreq[c]++;
        }
        
        int left = 0, right = 0;  // Pointers for the sliding window
        int minLen = INT_MAX;     // Minimum window length
        int minLeft = 0;          // Starting index of the minimum window

        int requiredChars = tFreq.size(); // Number of unique characters in t

        while (right < s.length()) {
            char currentChar = s[right];

            // Update window frequency
            windowFreq[currentChar]++;

            // Check if the current character is part of t and its frequency requirement is met
            if (tFreq.find(currentChar) != tFreq.end() && windowFreq[currentChar] == tFreq[currentChar]) {
                requiredChars--;
            }

            // Try to minimize the window by moving the left pointer
            while (requiredChars == 0) {
                // Update the minimum window if it is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                char leftChar = s[left];

                // Update window frequency
                windowFreq[leftChar]--;

                // Check if removing the leftmost character still satisfies the requirements
                if (tFreq.find(leftChar) != tFreq.end() && windowFreq[leftChar] < tFreq[leftChar]) {
                    requiredChars++;
                }

                // Move the left pointer to try to find a smaller window
                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }

        // Check if a valid window was found
        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};
This algorithm has a time co
