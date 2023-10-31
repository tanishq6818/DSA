// Given an array arr[] of n positive integers. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in-place.

// Example 1:

// Input:
// N = 5
// Arr[] = {3, 5, 0, 0, 4}
// Output: 3 5 4 0 0
// Explanation: The non-zero elements
// preserve their order while the 0
// elements are moved to the right.
// Example 2:

// Input:
// N = 4
// Arr[] = {0, 0, 0, 4}
// Output: 4 0 0 0
// Explanation: 4 is the only non-zero
// element and it gets moved to the left.
// Your Task:
// You don't need to read input or print anything. Complete the function pushZerosToEnd() which takes the array arr[] and its size n as input parameters and modifies arr[] in-place such that all the zeroes are moved to the right.  

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 0 ≤ arri ≤ 105

void pushZerosToEnd(int arr[], int n) {
        int left = 0; // Points to the current non-zero element
        int right = 0; // Used to iterate through the array
    
        while (right < n) {
            if (arr[right] != 0) {
                // Swap the non-zero element with the element at the left pointer
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                
                left++; // Move the left pointer to the next position
            }
            right++; // Move the right pointer to the next position
        }
    }
