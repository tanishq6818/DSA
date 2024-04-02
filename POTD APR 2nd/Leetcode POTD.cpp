Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    // Maps for character mapping from s to t and t to s
    unordered_map<char, char> sTot;
    unordered_map<char, char> tTos;

    for (int i = 0; i < s.length(); ++i) {
        char fromS = s[i];
        char fromT = t[i];

        // Check if the mapping exists in sTot
        if (sTot.find(fromS) != sTot.end()) {
            if (sTot[fromS] != fromT) return false; // Mismatch in mapping
        } else {
            // Insert the new mapping if it doesn't exist
            sTot[fromS] = fromT;
        }

        // Check if the mapping exists in tTos
        if (tTos.find(fromT) != tTos.end()) {
            if (tTos[fromT] != fromS) return false; // Mismatch in mapping
        } else {
            // Insert the new mapping if it doesn't exist
            tTos[fromT] = fromS;
        }
    }

    return true;
}
