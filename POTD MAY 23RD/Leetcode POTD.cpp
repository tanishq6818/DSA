You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
 

Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000
  class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;
        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Calculate subsets for each remainder group
        for (auto& fr : freqMap) {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            // Store counts of subsets for memoization
            vector<int> counts(subsets.size(), -1); 
            totalCount *= countBeautifulSubsets(subsets, subsets.size(), k, 0, counts);
        }
        return totalCount - 1;
    }

private:
    int countBeautifulSubsets(vector<pair<int, int>>& subsets, int numSubsets,
                              int difference, int i, vector<int>& counts) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // If the count is already calculated, return it
        if (counts[i] != -1) {
            return counts[i];
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(subsets, numSubsets, difference, i + 1,
                                         counts);

        // Calculate subsets where the current subset is taken
        int take = (1 << subsets[i].second) - 1; // take the current subset

        // If the next number has a difference of 'difference', calculate
        // subsets accordingly
        if (i + 1 < numSubsets &&
            subsets[i + 1].first - subsets[i].first == difference) {
            take *= countBeautifulSubsets(subsets, numSubsets, difference,
                                          i + 2, counts);
        } else {
            take *= countBeautifulSubsets(subsets, numSubsets, difference,
                                          i + 1, counts);
        }

        return counts[i] = skip + take; // Store and return total count of subsets
    }
};
