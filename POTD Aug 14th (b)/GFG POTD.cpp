// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

// Example 1:

// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.
// Example 2:

// Input:
// N = 1
// arr[] = {2, 1, 3, 2}
// Output:
// 1 3
// Explanation:
// 1 3 occur exactly once.
// Your Task:
// You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= length of array <= 106 
// 1 <= Elements in array <= 5 * 106

vector<int> singleNumber(std::vector<int> nums) {
    int xor_result = 0;
    
    // XOR all the numbers in the vector to get XOR of the two distinct numbers
    for (int num : nums) {
        xor_result ^= num;
    }
    
    // Find the rightmost set bit in xor_result
    int rightmost_set_bit = 1;
    while ((xor_result & rightmost_set_bit) == 0) {
        rightmost_set_bit <<= 1;
    }
    
    int group1 = 0;
    int group2 = 0;
    
    // Partition the vector into two groups based on the rightmost set bit
    for (int num : nums) {
        if (num & rightmost_set_bit) {
            group1 ^= num;
        } else {
            group2 ^= num;
        }
    }
    
    // Return the two distinct numbers in ascending order
    return {std::min(group1, group2), std::max(group1, group2)};
}
