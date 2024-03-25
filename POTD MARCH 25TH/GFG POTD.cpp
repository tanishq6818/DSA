// Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.

// Example 1:

// Input:  
// n = 2
// Output: 
// "11, 10"
// Explanation: Valid numbers are those where each prefix has more 1s than 0s:
// 11: all its prefixes (1 and 11) have more 1s than 0s.
// 10: all its prefixes (1 and 10) have more 1s than 0s.
// So, the output is "11, 10".
// Example 2:

// Input:  
// n = 3
// Output: 
// "111, 110, 101"
// Explanation: Valid numbers are those where each prefix has more 1s than 0s.
// 111: all its prefixes (1, 11, and 111) have more 1s than 0s.
// 110: all its prefixes (1, 11, and 110) have more 1s than 0s.
// 101: all its prefixes (1, 10, and 101) have more 1s than 0s.
// So, the output is "111, 110, 101".
// User Task:
// Your task is to complete the function NBitBinary() which takes a single number as input n and returns the list of strings in decreasing order. You need not take any input or print anything.

// Expected Time Complexity: O(|2n|)
// Expected Auxiliary Space: O(2n)

// Constraints:
// 1 <= n <= 15

void generateValidBinaryNumbers(vector<string>& result, string prefix, int ones, int zeros, int n) {
    // Base case: when the length of the prefix reaches n
    if (prefix.length() == n) {
        result.push_back(prefix);
        return;
    }

    // If the number of ones is greater than or equal to the number of zeros,
    // we can add '1' to the prefix and continue recursively
    if (ones >= zeros) {
        generateValidBinaryNumbers(result, prefix + '1', ones + 1, zeros, n);
    }

    // If the number of ones is greater than the number of zeros, we can add '0'
    // to the prefix and continue recursively
    if (ones > zeros) {
        generateValidBinaryNumbers(result, prefix + '0', ones, zeros + 1, n);
    }
}

vector<string> NBitBinary(int n) {
    vector<string> result;
    // Start the recursion with an empty prefix and counts of 0s and 1s as 0
    generateValidBinaryNumbers(result, "", 0, 0, n);
    return result;
}
