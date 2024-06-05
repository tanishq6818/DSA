// Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

// Note: Return 1 if there exists any such pair otherwise return -1.

// Example 1:

// Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
// Output: 1
// Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]
// Example 2:

// Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}
// Output: 1
// Explanation: We can swap 6 from array a[] and 2 from array b[]
// Expected Time Complexity: O(mlogm+nlogn).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ n, m ≤ 106
// 0 <= a[i], b[i] <= 105

int findSwapValues(int a[], int n, int b[], int m) {
    // Calculate the sums of both arrays
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
        sumA += a[i];
    for (int i = 0; i < m; i++)
        sumB += b[i];
    
    // Calculate the difference
    int diff = sumA - sumB;
    
    // If the difference is odd, return -1
    if (diff % 2 != 0)
        return -1;
    
    // Divide the difference by 2
    diff /= 2;
    
    // Sort both arrays
    std::sort(a, a + n);
    std::sort(b, b + m);
    
    // Use two pointers technique to find the pair
    int i = 0, j = 0;
    while (i < n && j < m) {
        int currentDiff = a[i] - b[j];
        if (currentDiff == diff)
            return 1;
        else if (currentDiff < diff)
            i++;
        else
            j++;
    }
    
    // If no such pair found, return -1
    return -1;
}
