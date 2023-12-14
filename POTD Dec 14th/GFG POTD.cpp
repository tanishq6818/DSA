//  Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 109 + 7.

// Example 1:

// Input:
// n = 3
// k = 2 
// Output: 6
// Explanation: 
// We have following possible combinations:

 

// Example 2:

// Input:
// n = 2
// k = 4 
// Output: 16
// Explanation: 
// After coloring first post with
// 4 possible combinations, you can still color
// next posts with all 4 colors. Total possible 
// combinations will be 4x4=16
// Your Task:
// Since, this is a function problem. You don't need to take any input or print anything, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted (modulo 109 + 7).

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 5000
// 1 ≤ K ≤ 100

  long long countWays(int n, int k)
    {
        //Creating an array to store the number of ways for each number of fences.
        long long dp[n + 1];

        //Initializing the dp array with 0.
        memset(dp, 0, sizeof(dp));

        //Setting the base case, when there is only 1 fence.
        dp[1] = k;

        //Initializing variables to keep count of same and different color fences.
        long long same = 0, diff = k;

        //Iterating over the fences starting from 2.
        for (int i = 2; i <= n; i++)
        {
            //Updating the value of same to the previous value of diff.
            same = diff;

            //Calculating the number of ways for different color fences.
            diff = dp[i-1] * (k-1);
            diff%=1000000007;

            //Calculating the total number of ways.
            dp[i] = (same + diff);
            dp[i]%=1000000007;
        }

        //Returning the number of ways for n fences.
        return dp[n];
    }
