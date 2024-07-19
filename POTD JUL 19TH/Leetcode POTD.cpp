Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

  class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        
        int rMinMax = INT_MIN;
        for (int i = 0; i < N; i++) {

            int rMin = INT_MAX;
            for (int j = 0; j < M; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rMinMax = max(rMinMax, rMin);
        }
        
        int cMaxMin = INT_MAX;
        for (int i = 0; i < M; i++) {

            int cMax = INT_MIN;
            for (int j = 0; j < N; j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            cMaxMin = min(cMaxMin, cMax);
        }
        
        if (rMinMax == cMaxMin) {
            return {rMinMax};
        }
        
        return {};
    }
};
