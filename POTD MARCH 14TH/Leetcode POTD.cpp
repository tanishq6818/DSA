Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
  class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;
        // {prefix: number of occurrence}
        unordered_map<int, int> freq; // To store the frequency of prefix sums

        for (int num : nums) {
            currentSum += num;
            if (currentSum == goal){
                totalCount++;
            }

            // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if (freq.find(currentSum - goal) != freq.end()){
                totalCount += freq[currentSum - goal];
            }

            freq[currentSum]++;
        }

        return totalCount;
    }
};
