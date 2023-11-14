// Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

// Example 1:

// Input:
// N = 5
// Arr[] = {3, 2, 4, 6, 5}
// Output: Yes
// Explanation: a=3, b=4, and c=5 forms a
// pythagorean triplet.
// Example 2:

// Input:
// N = 3
// Arr[] = {3, 8, 5}
// Output: No
// Explanation: No such triplet possible.
// Your Task:
// You don't have to take any input or print any thing. You have to complete the function checkTriplet() which takes an array arr, a single integer n, as input parameters and returns boolean denoting answer to the problem.
// Note: The driver will print "Yes" or "No" instead of corresponding to the boolean value returned.

// Expected Time Complexity: O(n+max(Arr[i])2)
// Expected Auxiliary Space: O(max(Arr[i]))

// Constraints:
// 1 <= n <= 105
// 1 <= arr[i] <= 1000

bool checkTriplet(int arr[], int n) {
    // Step 1: Create an array to store squares of elements
    int squared[n];
    for (int i = 0; i < n; i++) {
        squared[i] = arr[i] * arr[i];
    }

    // Step 2: Sort the squared array
    std::sort(squared, squared + n);

    // Step 3: Use Two Pointers to find a Pythagorean triplet
    for (int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;
        while (left < right) {
            if (squared[left] + squared[right] == squared[i]) {
                return true; // Found a Pythagorean triplet
            } else if (squared[left] + squared[right] < squared[i]) {
                left++;
            } else {
                right--;
            }
        }
    }

    return false; // No Pythagorean triplet found
}