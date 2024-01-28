Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8



  class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;

        // Calculate prefix sum for each row
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Iterate over all possible pairs of columns
        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                std::unordered_map<int, int> prefixSumCount;
                int currentSum = 0;
                
                // Iterate over each row and calculate prefix sum between the columns
                for (int row = 0; row < m; ++row) {
                    int prefixSum = matrix[row][right] - (left > 0 ? matrix[row][left - 1] : 0);
                    currentSum += prefixSum;
                    
                    // Check if the current sum equals the target
                    if (currentSum == target) {
                        result++;
                    }
                    
                    // Check if there is a previous prefix sum that can be subtracted to get the target
                    if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) {
                        result += prefixSumCount[currentSum - target];
                    }
                    
                    // Update the prefix sum count
                    prefixSumCount[currentSum]++;
                }
            }
        }

        return result;
    }
};
