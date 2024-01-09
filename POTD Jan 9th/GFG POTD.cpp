// Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices. 
// Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

// Example 1:

// Input:
// txt = "geeksforgeeks"
// pat = "geek"
// Output: 
// 1 9
// Explanation: 
// The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 
// Example 2:

// Input: 
// txt = "abesdu"
// pat = "edu"
// Output: 
// -1
// Explanation: 
// There's not substring "edu" present in txt.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function search() which takes the string txt and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string txt. 

// Expected Time Complexity: O(|txt|).
// Expected Auxiliary Space: O(|txt|).

// Constraints:
// 1 ≤ |txt| ≤ 105
// 1 ≤ |pat| < |S|
// Both the strings consists of lowercase English alphabets.

vector<int> computeLPS(string pat) {
    int m = pat.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> search(string pat, string txt) {
    vector<int> result;
    int m = pat.length();
    int n = txt.length();
    
    // Compute the prefix array (LPS) for the pattern
    vector<int> lps = computeLPS(pat);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            // Pattern found at index i-j+1
            result.push_back(i - j + 1);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}
