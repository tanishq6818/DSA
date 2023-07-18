// Best Time to Buy and Sell Stock II Sample Input 1 :
// 1
// 7
// 1 2 3 4 5 6 7
// Sample Output 1 :
// 6
// Explanation :
// We can make the maximum profit by buying the stock on the first day and selling it on the last day.
// Sample Input 2 :
// 1
// 7
// 7 6 5 4 3 2 1
// Sample Output 2 :
// 0
// Explanation :
// We can make the maximum profit by not buying the stock.
  
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    long max_profit = 0;
    for (int i = 1; i < n; i++) {
        // If the price of the current day is greater than the previous day, 
        // we can make a profit by buying the stock on the previous day and selling it on the current day.
        if (values[i] > values[i - 1]) {
            max_profit += values[i] - values[i - 1];
        }
    }
    return max_profit;
}
