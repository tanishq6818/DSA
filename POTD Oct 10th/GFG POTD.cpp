// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:

// Input:
// s = V
// Output: 5
// Example 2:

// Input:
// s = III 
// Output: 3
// Your Task:
// Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

// Expected Time Complexity: O(|S|), |S| = length of string S.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=roman no range<=3999

int romanToDecimal(string &s) {
    unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0; // Initialize with the value of the first character.

    for (int i = s.length() - 1; i >= 0; i--) {
        int currentValue = romanValues[s[i]];

        // If the current value is smaller than the previous one, subtract it.
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue; // Update the previous value for the next iteration.
    }

    return result;
}
