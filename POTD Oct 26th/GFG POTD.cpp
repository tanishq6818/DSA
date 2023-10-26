// Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:

// Double the number
// Add one to the number
// Example 1:

// Input:
// N = 8
// Output: 4
// Explanation: 
// 0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.
// Example 2:

// Input: 
// N = 7
// Output: 5
// Explanation: 
// 0 + 1 = 1 --> 1 + 1 = 2 --> 1 + 2 = 3 --> 3 * 2 = 6 --> 6 + 1 = 7.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minOperation() which accepts an integer N and return number of minimum operations required to reach N from 0.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 106


int minOperation(int N) {
    int count = 0; // Initialize a count to keep track of the number of operations

    while (N > 0) {
        if (N % 2 == 0) {
            N /= 2; // If N is even, double it
        } else {
            N -= 1; // If N is odd, subtract 1 to make it even
        }
        count++; // Increment the count for each operation
    }

    return count; // Return the total count of operations
}
