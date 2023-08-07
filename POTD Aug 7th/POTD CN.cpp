Permutation In String
string permutationExist(string str1, string str2, int n, int m) {
    if (n > m) {
        return "No"; // Permutation of str1 can't be a substring of str2 if its length is greater
    }
    
    unordered_map<char, int> freq1, freq2;
    
    // Count character frequencies in str1
    for (char c : str1) {
        freq1[c]++;
    }
    
    // Count character frequencies in a sliding window of size n in str2
    for (int i = 0; i < n; i++) {
        freq2[str2[i]]++;
    }
    
    // Check if the initial window contains a permutation of str1
    if (freq1 == freq2) {
        return "Yes";
    }
    
    // Slide the window through str2
    for (int i = n; i < m; i++) {
        freq2[str2[i - n]]--; // Remove the character that's no longer in the window
        if (freq2[str2[i - n]] == 0) {
            freq2.erase(str2[i - n]);
        }
        
        freq2[str2[i]]++; // Add the new character to the window
        
        if (freq1 == freq2) {
            return "Yes"; // Found a permutation of str1 in the current window
        }
    }
    
    return "No"; // No permutation of str1 found in str2
}
