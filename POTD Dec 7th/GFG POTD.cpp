// Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.

// Example 1:

// Input : 
// Arr = {2, 0, 11, 3, 0}
// L = 1 and R = 10
// Output : 
// 4
// Explanation:
// The sub-arrays {2}, {2, 0}, {3} and {3, 0} have maximum in range 1-10.
// Example 2:

// Input : 
// Arr = {3, 4, 1}
// L = 2 and R = 4
// Output : 
// 5
// Explanation:
// The sub-arrays {3}, {3, 4}, {3,4,1}, {4} and {4, 1} have maximum in range 2-4.
// Your Task:
// This is a function problem. The input is already taken care of by the driver code. You only need to complete the function countSubarrays() that takes an array arr, sizeOfArray (n), element L, integer R, and return the number of subarray with the maximum in range L-R. The driver code takes care of the printing.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ arr[i] ≤ 109
// 1 ≤ L ≤ R ≤ 109

class Solution{
    public:
    // function to calculate N*(N+1)/2
    long long countSubarrys(long long n)
    {
        return n * (n + 1) / 2LL;
    }
    
    // function to count the number of sub-arrays with
    // maximum greater then L and less then R.
    long long countSubarrays(int a[], int n, int L, int R)
    {
        long long res = 0;
    
        // exc is going to store count of elements
        // smaller than L in current valid subarray.
        // inc is going to store count of elements
        // smaller than or equal to R.
        long long exc = 0, inc = 0;
    
        // traverse through all elements of the array
        for (int i = 0; i < n; i++) {
    
            // If the element is greater than R,
            // add current value to result and reset
            // values of exc and inc.
            if (a[i] > R) {
                res += (countSubarrys(inc) - countSubarrys(exc));
                inc = 0;
                exc = 0;
            }
    
            // if it is less than L, then it is included
            // in the sub-arrays
            else if (a[i] < L) {
                exc++;
                inc++;
            }
    
            // if >= L and <= R, then count of
            // subarrays formed by previous chunk
            // of elements formed by only smaller
            // elements is reduced from result.
            else {
                res -= countSubarrys(exc);
                exc = 0;
                inc++;
            }
        }
    
        // Update result.
        res += (countSubarrys(inc) - countSubarrys(exc));
    
        // returns the count of sub-arrays
        return res;
    }
};
