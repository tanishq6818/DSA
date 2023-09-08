vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result;
    
    for (int i = 0; i < numRows; i++) {
        std::vector<int> row(i + 1, 1);  // Initialize each row with 1s
        
        // Calculate the values inside the row (excluding the first and last elements)
        for (int j = 1; j < i; j++) {
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        
        result.push_back(row);
    }
    
    return result;
}
