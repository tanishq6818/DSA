// Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10} are 
// possible subsets.
// Example 2:
// Input: N = 5, arr[] = {1, 2, 3, 4, 5}
//        sum = 10
// Output: 3
// Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
// {2, 3, 5} are possible subsets.
// Your Task:  
// You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

// Expected Time Complexity: O(N*sum)
// Expected Auxiliary Space: O(N*sum)

// Constraints:
// 1 ≤ N*sum ≤ 106
// 0<=arr[I]<=106
class Solution{

    int mod = (int)(1e9 + 7); // Initialize mod value for calculations
    vector<vector<int>> dp; // 2D vector to store dynamic programming values
    int N; // Size of the array

    int fun(int pos, int sum, int arr[]) {
        if (pos >= N)
            return sum == 0; // Check if sum is zero when array position reaches end

        int &ans = dp[pos][sum]; // Reference to store calculated value in dp vector
        if (ans != -1)
            return ans; // Return the already calculated value from dp vector

        ans = 0; // Initialize answer with zero

        ans += fun(pos + 1, sum, arr); // Recursively call function for next position with sum unchanged
        ans %= mod; // Take modulo of the answer to avoid overflow
        if (arr[pos] <= sum)
            ans += fun(pos + 1, sum - arr[pos], arr), ans %= mod; // Recursively call function for next position with reduced sum

        return ans; // Return the calculated answer
           
    }

    public:
    int perfectSum(int arr[], int n, int sum)
    {
        dp.assign(n + 1, vector<int> (sum + 2, -1)); // Initialize dp vector with -1
        N = n; // Assign n to N variable
        
        return fun(0, sum, arr); // Call recursive function with initial parameters
    }
};
