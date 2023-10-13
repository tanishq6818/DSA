// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
 

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if (n == 2) {
            return min(cost[0], cost[1]); // There are only two steps, return the minimum cost.
        }
        
        // Create an array to store the minimum cost to reach each step.
        vector<int> dp(n);
        
        // Initialize the first two steps with their respective costs.
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // Calculate the minimum cost for each step starting from the third step.
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        
        // The minimum cost to reach the top is the minimum of the last two steps.
        return min(dp[n - 1], dp[n - 2]);
    }
};
