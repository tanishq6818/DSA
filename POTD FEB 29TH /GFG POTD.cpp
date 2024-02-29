Given an array integers arr[], containing n elements, find the sum of bit differences between all pairs of element in the array. Bit difference of a pair (x, y) is the count of different bits at the same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 respectively and the first and last bits differ between the two numbers.

Note: (x, y) and (y, x) are considered two separate pairs.

Example 1:

Input: 
n = 2
arr[] = {1, 2}
Output: 4
Explanation: All possible pairs of an array are (1, 1), (1, 2), (2, 1), (2, 2).
Sum of bit differences = 0 + 2 + 2 + 0
                       = 4
Example 2:

Input:
n = 3 
arr[] = {1, 3, 5}
Output: 8
Explanation: 
All possible pairs of an array are (1, 1), (1, 3), (1, 5), (3, 1), (3, 3) (3, 5),(5, 1), (5, 3), (5, 5).
Sum of bit differences = 0 + 1 + 1 + 1 + 0 + 2 + 1 + 2 + 0 
                       = 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function sumBitDifferences() which takes the array arr[] and n as inputs and return an integer that represents the sum of the bit differences between all possible pairs of elements in the array.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 105
1 <= arr[i] <= 105
long long sumBitDifferences(int arr[], int n) {
    long long result = 0; // Initialize result to store the sum of bit differences

    // Iterate through each bit position
    for (int i = 0; i < 32; ++i) {
        // Count the number of set bits and unset bits at the current bit position
        int setBits = 0, unsetBits = 0;

        // Iterate through all elements in the array
        for (int j = 0; j < n; ++j) {
            // Check if the current bit is set or unset for the current element
            if ((arr[j] & (1 << i)) != 0) {
                setBits++;
            } else {
                unsetBits++;
            }
        }

        // Add the product of setBits and unsetBits to the result
        result += (long long)setBits * unsetBits;
    }

    return 2 * result; // Multiply by 2 to consider (x, y) and (y, x) separately
}


