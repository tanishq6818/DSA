
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        for (int i = pow(2, n); i < pow(2, n + 1); ++i) {
            // generate bitmask, from 0..00 to 1..11
            string bitmask = bitset<32>(i).to_string().substr(32 - n);
            // append subset corresponding to that bitmask
            vector<int> curr;
            for (int j = 0; j < n; ++j) {
                if (bitmask.at(j) == '1') curr.push_back(nums[j]);
            }
            output.push_back(curr);
        }
        return output;
    }
};
