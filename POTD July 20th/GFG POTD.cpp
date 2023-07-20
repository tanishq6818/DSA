// Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

// Example 1:

// Input:
// S = hello
// Output: h
// Explanation: In the given string, the
// first character which is non-repeating
// is h, as it appears first and there is
// no other 'h' in the string.
// Example 2:

// Input:
// S = zxvczbtxyzvy
// Output: c
// Explanation: In the given string, 'c' is
// the character which is non-repeating. 
// Your Task:
// You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$'


char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char, int> frequencyMap;
    
        // Count the frequency of each character in the string
        for (char c : S) {
            frequencyMap[c]++;
        }
    
        // Find the first non-repeating character
        for (char c : S) {
            if (frequencyMap[c] == 1) {
                return c;
            }
        }
    
        return '$'; // If no non-repeating character found, return '$'

       
    }
