// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.

// If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 
// 1
// Explanation: 
// There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
// Example 2:

// Input:
// str1 = aab
// str2 = xyz
// Output: 
// 0
// Explanation: 
// There are two different characters in aab but there are three different charactersin xyz. So there won't be one to one mapping between str1 and str2.
// Your Task:
// You don't need to read input or print anything.Your task is to complete the function areIsomorphic() which takes the string str1 and string str2 as input parameter and  check if two strings are isomorphic. The function returns true if strings are isomorphic else it returns false.

// Expected Time Complexity: O(|str1|+|str2|).
// Expected Auxiliary Space: O(Number of different characters).
// Note: |s| represents the length of string s.

// Constraints:
// 1 <= |str1|, |str2| <= 105

bool areIsomorphic(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, char> map1, map2;

    for (int i = 0; i < str1.length(); ++i) {
        // Check mapping from str1 to str2
        if (map1.find(str1[i]) == map1.end()) {
            map1[str1[i]] = str2[i];
        } else if (map1[str1[i]] != str2[i]) {
            return false;
        }

        // Check mapping from str2 to str1
        if (map2.find(str2[i]) == map2.end()) {
            map2[str2[i]] = str1[i];
        } else if (map2[str2[i]] != str1[i]) {
            return false;
        }
    }

    return true;
}
