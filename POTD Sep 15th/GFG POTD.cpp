// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Example 1:

// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation: 
// The two parts are {1, 5, 5} and {11}.
// Example 2:

// Input: N = 3
// arr = {1, 3, 5}
// Output: NO
// Explanation: This array can never be 
// partitioned into two such parts.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

// Expected Time Complexity: O(N*sum of elements)
// Expected Auxiliary Space: O(N*sum of elements)

// Constraints:
// 1 ≤ N ≤ 100
// 1 ≤ arr[i] ≤ 1000
// N*sum of elements ≤ 5*106
int equalPartition(int N, int arr[]) {
    int sum = 0;
    
    // Calculate the total sum of the elements in the array
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    // If the total sum is odd, it can't be divided into two equal subsets
    if (sum % 2 != 0) {
        return 0;
    }

    // Calculate half of the total sum
    int targetSum = sum / 2;

    // Create a 2D DP array to store the subset sum possibilities
    bool dp[N + 1][targetSum + 1];

    // Initialize the DP array
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= targetSum; j++) {
            if (i == 0) {
                dp[i][j] = false;
            } else if (j == 0) {
                dp[i][j] = true;
            } else if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // If dp[N][targetSum] is true, it means it's possible to partition the array
    // into two subsets with equal sum
    if (dp[N][targetSum]) {
        return 1;
    } else {
        return 0;
    }
}
