Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.

  class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int words_size = words.size();
        vector<int> commonCharacterCounts(26), currentCharacterCounts(26);
        vector<string> result;

        // Initialize commonCharacterCounts with the characters from the first
        // word
        for (char& ch : words[0]) {
            commonCharacterCounts[ch - 'a']++;
        }

        for (int i = 1; i < words_size; i++) {
            fill(currentCharacterCounts.begin(), currentCharacterCounts.end(),
                 0);

            // Count characters in the current word
            for (char& ch : words[i]) {
                currentCharacterCounts[ch - 'a']++;
            }

            // Update the common character counts to keep the minimum counts
            for (int letter = 0; letter < 26; letter++) {
                commonCharacterCounts[letter] =
                    min(commonCharacterCounts[letter],
                        currentCharacterCounts[letter]);
            }
        }

        // Collect the common characters based on the final counts
        for (int letter = 0; letter < 26; letter++) {
            for (int commonCount = 0;
                 commonCount < commonCharacterCounts[letter]; commonCount++) {
                result.push_back(string(1, letter + 'a'));
            }
        }

        return result;
    }
};
