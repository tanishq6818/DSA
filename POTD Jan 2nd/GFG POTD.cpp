Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input : 
n = 4
a[] = {1, -2, 2, -3}
k = 2
Output : 
1
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, -2}
Example 2:
Input :
n = 6 
a[] = {1, 1, 1, 1, 1, 1}
k = 2
Output : 
6
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, 1, 1, 1, 1, 1}
Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSumWithK() which takes the array a[], its size n and an integer k as inputs and returns the value of the largest sum of the subarray containing at least k numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
-105 <= a[i] <= 105
1 <= k <= n


// Returns maximum sum of a subarray with at-least
// k elements.
class Solution{
    public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        // maxSum[i] is going to store maximum sum
        // till index i.
        long long int maxSum[n];
        maxSum[0] = a[0];
    
        // We use Kadane's algorithm to fill maxSum[]
        // Below code is taken from method 3 of
        // http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
        long long int curr_max = a[0];
        for (long long int i = 1; i < n; i++) {
            curr_max = max(a[i], curr_max + a[i]);
            maxSum[i] = curr_max;
        }
    
        // Sum of first k elements
        long long int sum = 0;
        for (long long int i = 0; i < k; i++) sum += a[i];
    
        // Use the concept of sliding window
        long long int result = sum;
        for (long long int i = k; i < n; i++) {
            // Compute sum of k elements ending
            // with a[i].
            sum = sum + a[i] - a[i - k];
    
            // Update result if required
            result = max(result, sum);
    
            // Include maximum sum till [i-k] also
            // if it increases overall max.
            result = max(result, sum + maxSum[i - k]);
        }
        return result;
    }
};
