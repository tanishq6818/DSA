// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
// Example 2:

// Input: nums = [9], target = 3
// Output: 0

int combinationSum4(std::vector<int>& nums, int target) {
    std::vector<unsigned int> dp(target + 1, 0); // dp[i] represents the number of combinations to reach target i
    dp[0] = 1; // There's one way to reach target 0, which is by not selecting any number
    
    for (int i = 1; i <= target; ++i) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }
    
    return dp[target];
}
