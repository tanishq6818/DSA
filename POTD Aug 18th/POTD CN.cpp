// You are given a 32-bit integer 'N'. At the right of the leftmost set bit, your task is to

// check if there are no two adjacent bits that are the same.

// For Example:

// 42 is valid because it's binary representation '101010' has no two

// adjacent bits that are the same. Sample Input 1:
// 2
// 21
// 31
// Sample Output 1:
// true
// false
// Explanation For Sample Input 1:
// In example 1, binary representation of 21 is '10101'. Since, no two adjacent bits are the same here, it is valid.
// In example 2, binary representation of 31 is ‘11111’. All the digits of binary representation are the same, hence it is not valid.
// Sample Input 2:
// 2
// 20
// 85
// Sample Output 2:
// false
// true
// Explanation For Sample Input 2:
// In example 1, binary representation of 20 is '10100'. Since, the 0-th and 1-st digits of the binary number are the same, it is invalid.
// In example 2, binary representation of 85 is ‘1010101’. Since, no two adjacent bits are the same here, it is valid.


bool checkBits(unsigned int n) {
    bool prevBit = n & 1; // Get the rightmost bit of the number
    n >>= 1; // Shift the number to the right

    while (n > 0) {
        bool currentBit = n & 1; // Get the current bit
        if (currentBit == prevBit) {
            return false; // Adjacent bits are the same
        }
        prevBit = currentBit; // Update prevBit for the next iteration
        n >>= 1; // Shift the number to the right
    }
    
    return true; // No adjacent bits are the same
}
