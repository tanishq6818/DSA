// Given two arrays nums1 and nums2.

// Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

// A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

// Example 1:

// Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
// Output: 18
// Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
// Their dot product is (2*3 + (-2)*(-6)) = 18.
// Example 2:

// Input: nums1 = [3,-2], nums2 = [2,-6,7]
// Output: 21
// Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
// Their dot product is (3*7) = 21.
// Example 3:

// Input: nums1 = [-1,-1], nums2 = [1,1]
// Output: -1
// Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
// Their dot product is -1.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 500
// -1000 <= nums1[i], nums2[i] <= 1000
class Solution {
public:
    vector<vector<int>> memo;
    
    int dp(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        
        int use = nums1[i] * nums2[j] + dp(i + 1, j + 1, nums1, nums2);
        memo[i][j] = max(use, max(dp(i + 1, j, nums1, nums2), dp(i, j + 1, nums1, nums2)));
        return memo[i][j];
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

        memo = vector(nums1.size(), vector(nums2.size(), 0));
        return dp(0, 0, nums1, nums2);
    }
};
