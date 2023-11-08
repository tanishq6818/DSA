//snake pattern
vector<int> snakePattern(vector<vector<int>> matrix) {
    vector<int> result;

    for (int i = 0; i < matrix.size(); i++) {
        if (i % 2 == 0) {
            // When row number is even, go left to right
            for (int j = 0; j < matrix[i].size(); j++) {
                result.push_back(matrix[i][j]);
            }
        } else {
            // When row number is odd, go right to left
            for (int j = matrix[i].size() - 1; j >= 0; j--) {
                result.push_back(matrix[i][j]);
            }
        }
    }

    return result;
}
