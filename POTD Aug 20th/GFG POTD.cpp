// Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

// Example 1:

// Input:
// N = 7, X = 2
// Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output: 4
// Explanation: 2 occurs 4 times in the
// given array.
// Example 2:

// Input:
// N = 7, X = 4
// Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output: 0
// Explanation: 4 is not present in the
// given array.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
// If x is not present in the array (arr) then return 0.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ 106
// 1 ≤ X ≤ 106

int count(int arr[], int n, int x) {
        // Find the first occurrence of X
        int first = -1;
        int low = 0, high = n - 1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == x) {
                first = mid;
                high = mid - 1; // Look for first occurrence on the left side
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        if (first == -1) {
            return 0; // X is not present in the array
        }
    
        // Find the last occurrence of X
        int last = -1;
        low = 0, high = n - 1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == x) {
                last = mid;
                low = mid + 1; // Look for last occurrence on the right side
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return (last - first + 1);
    }
