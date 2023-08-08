// Problem Statement

// You are given a string 'S' consisting of lower-case English alphabets, find the number of good splits. Splitting a string 'S' into two non-empty strings 'X and 'Y' is called good if the number of unique characters in strings 'X' and 'Y' is equal

// For Example:

// If string S is equal to "abadaa".

// Then S can be split in the following ways: X = "a" and Y = "badaa", string X has 1 unique character and Y has 3 unique

// characters.

// X = "ab" and Y = "adaa", string X has 2 unique characters and Y has 2 unique

// characters. [GOOD SPLIT]

// X = "aba" and Y = "daa", string X has 2

// unique characters and y has 2 unique characters. [GOOD SPLIT]

// X = "abad" and Y = "aa", string X has 3 unique characters and Y has 1 unique

// character.

// X = "abada" and y = "a", string X has 3 unique characters and Y has 1 unique character. Therefore we will return value 2 as we are able to find 2 good splits.

// Sample Input 1 :
// 2
// abadaa
// abcde
// Sample Output 1 :
// 2
// 0 
// Explanation For Sample Input 1 :
// For test case 1 : 
// We will return 2, because only 2 good splits are possible as shown below:
// X = “a” and Y = “badaa”, string X has 1 unique character and Y has 3 unique characters.
// X = “ab” and Y = “adaa”, string X has 2 unique characters and Y has 2 unique characters.[GOOD SPLIT]
// X = “aba” and Y = “daa”, string X has 2 unique characters and Y has 2 unique characters.[GOOD SPLIT]
// X = “abad” and Y = “aa”, string X has 3 unique characters and Y has 1 unique character.
// X = “abada” and Y = “a”, string X has 3 unique characters and Y has 1 unique character.

// For test case 2 : 
// We will return 0, because no good split is possible. All possible splits are shown:
// X = “a” and Y = “bcde”, string X has 1 unique character and Y has 4 unique characters.
// X = “ab” and Y = “cde”, string X has 2 unique characters and Y has 3 unique characters. 
// X = “abc” and Y = “de”, string X has 3 unique characters and Y has 2 unique characters.
// X = “abcd” and Y = “e”, string X has 4 unique characters and Y has 1 unique character.
// Sample Input 2 :
// 2
// codingninjas
// codestudio
// Sample Output 2 :
// 0
// 1 

int splitString(string s) {
    int n = s.size();
    int goodSplits = 0;

    for (int i = 1; i < n; ++i) {
        unordered_set<char> left, right;

        // Add characters to the left set
        for (int j = 0; j < i; ++j) {
            left.insert(s[j]);
        }

        // Add characters to the right set
        for (int j = i; j < n; ++j) {
            right.insert(s[j]);
        }

        // Compare the sizes of the sets
        if (left.size() == right.size()) {
            ++goodSplits;
        }
    }

    return goodSplits;
}
