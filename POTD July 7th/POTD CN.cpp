// Sample Input 1 :
// 2
// 2 3
// 1 5 3
// 2 9 4
// 3 3
// 1 4 5
// 2 3 5
// 6 7 8
// Sample Output 1 :
// 5
// 10
// Explanation Of Sample Input 1 :
// Test Case 1 :

// In this case, Ninja can paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
// Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5 .

// Hence the minimum cost will be 5.

// Test case 2 :

// In this case, Ninja can paint house 0 into color 0, paint house 1 into color 1, paint house 2 in color 0. Minimum cost : 1 + 3 + 6 = 10.
// Sample Input 2 :
// 2
// 2 3
// 1 2 3
// 10 11 12 
// 1 2
// 4 2
// Sample Output 2 :
// 12
// 2

int paintCost(int n, int k, vector<vector<int>>& costs) {
    // Create a 2D DP array to store the minimum costs
    vector<vector<int>> dp(n, vector<int>(k, 0));

    // Initialize the first row with the costs of the first house
    for (int i = 0; i < k; i++) {
        dp[0][i] = costs[0][i];
    }

    // Iterate through the remaining houses
    for (int i = 1; i < n; i++) {
        // Calculate the minimum cost for each color
        for (int j = 0; j < k; j++) {
            // Find the minimum cost up to the previous house
            int minPrevCost = INT_MAX;
            for (int p = 0; p < k; p++) {
                if (p != j) {
                    minPrevCost = min(minPrevCost, dp[i - 1][p]);
                }
            }
            dp[i][j] = costs[i][j] + minPrevCost;
        }
    }

    // Find the minimum cost from the last row
    int minCost = INT_MAX;
    for (int i = 0; i < k; i++) {
        minCost = min(minCost, dp[n - 1][i]);
    }

    return minCost;
}
