// Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

// Example 1:

// Input:
// n = 5
// arr = {4,2,-3,1,6}
// Output: 
// Yes
// Explanation: 
// 2, -3, 1 is the subarray with sum 0.
// Example 2:

// Input:
// n = 5
// arr = {4,2,0,1,6}
// Output: 
// Yes
// Explanation: 
// 0 is one of the element in the array so there exist a subarray with sum 0.
// Your Task:
// You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 104
// -105 <= a[i] <= 105

bool subArrayExists(int arr[], int n) {
    std::unordered_set<int> prefixSumSet;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];

        // If the current sum is 0 or it has been seen before, return true
        if (sum == 0 || prefixSumSet.find(sum) != prefixSumSet.end()) {
            return true;
        }

        // Add the current sum to the set
        prefixSumSet.insert(sum);
    }

    // If no subarray with sum 0 is found
    return false;
}
