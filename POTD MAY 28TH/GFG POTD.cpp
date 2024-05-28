// Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of oranges. The cost array has a 1-based indexing. If buying exactly w kg of oranges is impossible, then return -1.
// Note:
// 1. cost[i] = -1 means that i kg packet of orange is unavailable.
// 2. It may be assumed that there is an infinite supply of all available packet types.

// Example 1:

// Input: 
// n = 5
// cost[] = {20, 10, 4, 50, 100} 
// w = 5
// Output: 
// 14
// Explanation: 
// Purchase the 2kg packet for 10 coins and the 3kg packet for 4 coins to buy 5kg of oranges for 14 coins.
// Example 2:

// Input: 
// n = 5
// cost[] = {-1, -1, 4, 3, -1}
// w = 5
// Output: 
// -1
// Explanation: 
// It is not possible to buy 5 kgs of oranges.
// Your Task:  
// You don't need to read input or print anything. Complete the function minimumCost() which takes integers n and w, and integer array cost[] as input parameters and returns the minimum cost to buy exactly w kg of oranges, If buying exactly w kg of oranges is impossible, then return -1.

// Expected Time Complexity: O(n*w)
// Expected Auxiliary Space: O(n*w)

// Constraints:
// 1 ≤ n, w ≤ 2*102
// 1 ≤ cost[i] ≤ 105
// cost[i] ≠ 0

int minimumCost(int n, int w, vector<int> cost) {

        int INF = 999999999;

        // val[] and wt[] arrays
        // val[] array to store cost of 'i' kg packet of orange
        // wt[] array weight of packet of orange
        vector<int> val, wt;

        // traverse the original cost[] array and skip
        // unavailable packets and make val[] and wt[]
        // array. size variable tells the available number
        // of distinct weighted packets
        int size = 0;
        for (int i = 0; i < n; i++) {
            if (cost[i] != -1) {
                val.push_back(cost[i]);
                wt.push_back(i + 1);
                size++;
            }
        }

        n = size;
        int min_cost[n + 1][w + 1];

        // fill 0th row with infinity
        for (int i = 0; i <= w; i++)
            min_cost[0][i] = INF;

        // fill 0'th column with 0
        for (int i = 1; i <= n; i++)
            min_cost[i][0] = 0;

        // now check for each weight one by one and fill the
        // matrix according to the condition
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                // wt[i-1]>j means capacity of bag is
                // less then weight of item
                if (wt[i - 1] > j)
                    min_cost[i][j] = min_cost[i - 1][j];

                // here we check we get minimum cost either
                // by including it or excluding it
                else
                    min_cost[i][j] = min(min_cost[i - 1][j],
                                         min_cost[i][j - wt[i - 1]] + val[i - 1]);
            }
        }

        // exactly weight W can not be made by given weights
        return (min_cost[n][w] == INF) ? -1 : min_cost[n][w];
    }
