// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

 vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Compute prefix products
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        int suffix_product = 1;
        
        // Compute suffix products and multiply them with the prefix products
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix_product;
            suffix_product *= nums[i];
        }
        
        return result;
    }
