// Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

// Example 1 :

// Input : 
// nums = [9, 5, 7, 3]
// k = 6
// Output: 
// True
// Explanation: 
// {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.
// Example 2:

// Input : 
// nums = [4, 4, 4]
// k = 4
// Output: 
// False
// Explanation: 
// You can make 1 pair at max, leaving a single 4 unpaired.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function canPair() which takes array nums and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

// Expected Time Complexity: O(n)
// Expected Space Complexity : O(n)

// Constraints:
// 1 <= length( nums ) <= 105
// 1 <= numsi <= 105
// 1 <= k <= 105


bool canPair(vector<int> nums, int k) {
    // If the number of elements in nums is odd, it's not possible to form pairs
    if (nums.size() % 2 != 0) {
        return false;
    }

    // Create a hash map to store the frequency of remainders when each element is divided by k
    unordered_map<int, int> remainderCount;

    // Count the frequency of each remainder
    for (int num : nums) {
        int remainder = (num % k + k) % k;  // Ensure remainder is non-negative
        remainderCount[remainder]++;
    }

    // Check for pairs with remainder 0
    if (remainderCount[0] % 2 != 0) {
        return false;
    }

    // Check for pairs with remainder i and k-i (excluding remainder 0)
    for (int i = 1; i <= k / 2; i++) {
        if (remainderCount[i] != remainderCount[k - i]) {
            return false;
        }
    }

    // All conditions satisfied, return true
    return true;
}
