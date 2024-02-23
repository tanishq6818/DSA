// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell). The stock prices throughout the day are represented in the form of an array of prices. 

// Given an array price of size n, find out the maximum profit that a share trader could have made.

// Example 1:

// Input:
// n = 6
// prices[] = {10,22,5,75,65,80}
// Output:
// 87
// Explanation:
// Trader earns 87 as sum of 12, 75 Buy at 10, sell at 22, Buy at 5 and sell at 80.
// Example 2:

// Input:
// n = 7
// prices[] = {2,30,15,10,8,25,80}
// Output:
// 100
// Explanation:
// Trader earns 100 as sum of 28 and 72 Buy at price 2, sell at 30, Buy at 8 and sell at 80,
// Your Task:

// Complete the function maxProfit() which takes an integer array price as the only argument and returns an integer, representing the maximum profit, if only two transactions are allowed.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:

// 1 <= n <= 105
// 1 <= price[i] <= 105

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;

    // Arrays to store the maximum profit for the first and second transactions at each day
    vector<int> firstTransaction(n, 0);
    vector<int> secondTransaction(n, 0);

    // Initialize the maximum profit after the first transaction for each day
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        firstTransaction[i] = max(firstTransaction[i - 1], prices[i] - minPrice);
    }

    // Initialize the maximum profit after the second transaction for each day
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        secondTransaction[i] = max(secondTransaction[i + 1], maxPrice - prices[i]);
    }

    // Calculate the maximum total profit by combining the first and second transactions
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, firstTransaction[i] + (i + 1 < n ? secondTransaction[i + 1] : 0));
    }

    return maxProfit;
}
