// Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.

// Example 1: 

// Input: 
// M = 11, N = 9
// Output: 
// 2
// Explanation: 
// Binary representation of the given numbers are: 1011 and 1001, 2nd bit from right is different.
// Example 2:

// Input: 
// M = 52, N = 4
// Output: 
// 5
// Explanation: 
// Binary representation of the given numbers are: 110100 and 0100, 5th-bit from right is different.
// User Task:
// The task is to complete the function posOfRightMostDiffBit() which takes two arguments M and N and returns the position of first different bits in M and N from right. If both m and n are the same then return -1 in this case.

// Expected Time Complexity: O(max(log M, log N)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= M, N <= 109

int posOfRightMostDiffBit(int m, int n) {
    // XOR of M and N will give a number with set bits at positions where M and N differ
    int xorResult = m ^ n;

    // If M and N are the same, return -1
    if (xorResult == 0) {
        return -1;
    }

    // Find the position of the rightmost set bit in the XOR result
    int position = 1;
    while ((xorResult & 1) == 0) {
        xorResult >>= 1;
        position++;
    }

    return position;
}