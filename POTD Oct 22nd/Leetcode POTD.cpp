// You are given an array of integers nums (0-indexed) and an integer k.

// The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

// Return the maximum possible score of a good subarray.

 

// Example 1:

// Input: nums = [1,4,3,7,4,5], k = 3
// Output: 15
// Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
// Example 2:

// Input: nums = [5,5,4,5,4,1,1,1], k = 0
// Output: 20
// Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 2 * 104
// 0 <= k < nums.length


int maximumScore(vector<int>& nums, int k) {
        int ans = solve(nums, k);
        reverse(nums.begin(), nums.end());
        return max(ans, solve(nums, nums.size() - k - 1));
    }

    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(k, 0);
        int currMin = INT_MAX;
        for (int i = k - 1; i >= 0; i--) {
            currMin = min(currMin, nums[i]);
            left[i] = currMin;
        }
        
        vector<int> right;
        currMin = INT_MAX;
        for (int i = k; i < n; i++) {
            currMin = min(currMin, nums[i]);
            right.push_back(currMin);
        }
        
        int ans = 0;
        for (int j = 0; j < right.size(); j++) {
            currMin = right[j];
            int i = lower_bound(left.begin(), left.end(), currMin) - left.begin();
            int size = (k + j) - i + 1;
            ans = max(ans, currMin * size);
        }
        
        return ans;
    }
