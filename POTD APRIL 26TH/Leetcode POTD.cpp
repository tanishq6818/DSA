Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
Example 2:

Input: grid = [[7]]
Output: 7
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99

  class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Initialize a two-dimensional array to cache the result of each sub-problem
        vector<vector<int>> memo(grid.size(), vector<int>(grid.size(), INT_MAX));

        // Fill the base case
        for (int col = 0; col < grid.size(); col++) {
            memo[grid.size() - 1][col] = grid[grid.size() - 1][col];
        }

        // Fill the recursive cases
        for (int row = grid.size() - 2; row >= 0; row--) {
            for (int col = 0; col < grid.size(); col++) {
                // Select minimum from valid cells of next row
                int nextMinimum = INT_MAX;
                for (int nextRowCol = 0; nextRowCol < grid.size(); nextRowCol++) {
                    if (nextRowCol != col) {
                        nextMinimum = min(nextMinimum, memo[row + 1][nextRowCol]);
                    }
                }

                // Minimum cost from this cell
                memo[row][col] = grid[row][col] + nextMinimum;
            }
        }

        // Find the minimum from the first row
        int answer = INT_MAX;
        for (int col = 0; col < grid.size(); col++) {
            answer = min(answer, memo[0][col]);
        }

        // Return the answer
        return answer;
    }
};
