Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        
        while (i < heights.size() || !s.empty()) {
            if (s.empty() || (i < heights.size() && heights[i] >= heights[s.top()])) {
                s.push(i);
                ++i;
            } else {
                int top = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, heights[top] * width);
            }
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols, 0));
        int maxArea = 0;
        
        // Construct the histogram for each row
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i > 0) ? heights[i - 1][j] + 1 : 1;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights[i]));
        }
        
        return maxArea;
    }
