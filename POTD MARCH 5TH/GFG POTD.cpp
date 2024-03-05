// Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.

// Example 1:

// Input:
// n = 2
// a[] = {1, 10}
// Output:
// 1
// Explanation:
// a[0] < a[1] so (j-i) is 1-0 = 1.
// Example 2:

// Input:
// n = 9
// a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j]) thus giving the maximum difference of j - i which is 6(7-1).
// Your Task:
// The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code. 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ n ≤ 106
// 0 ≤ a[i] ≤ 109

int maxIndexDiff(int a[], int n) {
    // Create an array to store the indexes of the elements
    vector<pair<int, int>> arrIdx(n);

    // Initialize the array with element values and their corresponding indexes
    for (int i = 0; i < n; i++) {
        arrIdx[i].first = a[i];
        arrIdx[i].second = i;
    }

    // Sort the array based on the element values
    sort(arrIdx.begin(), arrIdx.end());

    // Create an array to store the minimum index encountered so far
    int minIdx[n];
    minIdx[0] = arrIdx[0].second;

    // Fill the minIdx array with the minimum index encountered so far
    for (int i = 1; i < n; i++) {
        minIdx[i] = min(minIdx[i - 1], arrIdx[i].second);
    }

    // Initialize the maximum difference
    int maxDiff = 0;

    // Traverse the array and update the maximum difference if the condition is satisfied
    for (int i = n - 1; i > 0; i--) {
        maxDiff = max(maxDiff, arrIdx[i].second - minIdx[i - 1]);
    }

    return maxDiff;
}

