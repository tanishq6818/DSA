Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

  class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> characterSet;
        int res = 0;

        // Loop over characters in the string
        for (char c : s) {
            // If set contains the character, match found
            if (characterSet.find(c) != characterSet.end()) {
                characterSet.erase(c);
                // add the two occurrences to our palindrome
                res += 2;
            } else {
                // add the character to the set
                characterSet.insert(c);
            }
        }

        // if any character remains, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (!characterSet.empty()) {
            res++;
        }

        return res;
    }
};
