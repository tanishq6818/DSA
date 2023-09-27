// Given two sorted arrays arr and brr and a number x, find the pair whose sum is closest to x and the pair has an element from each array. In the case of multiple closest pairs return any one of them.
// Note: Can return the two numbers in any manner.

// Example 1:

// Input : N = 4, M = 4
// arr[ ] = {1, 4, 5, 7}
// brr[ ] = {10, 20, 30, 40} 
// X = 32
// Output : 1
// Explanation:
// The closest pair whose sum is closest
// to 32 is {1, 30} = 31.
// Example 2:

// Input : N = 4, M = 4
// arr[ ] = {1, 4, 5, 7}
// brr[ ] = {10, 20, 30, 40}
// X = 50 
// Output :  3 
// Explanation: 
// The closest pair whose sum is closest
// to 50 is {7, 40} = 47.
// Your Task:
// You only need to complete the function printClosest() that takes an array (arr), another array (brr), size of array arr (N), size of array brr (M), and return the array of two integers whose sum is closest to X. The driver code takes care of the printing of the closest difference.

// Expected Time Complexity: O(N+M).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N, M ≤ 105
// 1 ≤ A[i], B[i] ≤ 109

vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
    int left = 0, right = m - 1;
    int minDiff = INT_MAX;
    vector<int> result;

    while (left < n && right >= 0) {
        int sum = arr[left] + brr[right];
        int diff = abs(sum - x);

        if (diff < minDiff) {
            minDiff = diff;
            result = {arr[left], brr[right]};
        }

        if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}
