// Given an array arr[] of size N of positive integers which may have duplicates. The task is to find the maximum and second maximum from the array, and both of them should be different from each other, so If no second max exists, then the second max will be -1.

// Example 1:

// Input:
// N = 3
// arr[] = {2,1,2}
// Output: 2 1
// Explanation: From the given array 
// elements, 2 is the largest and 1 
// is the second largest.
// Example 2:

// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 5 4
// Explanation: From the given array 
// elements, 5 is the largest and 4 
// is the second largest.


vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]) {
        int max = INT_MIN;
        int max2 = INT_MIN;
    
        for (int i = 0; i < sizeOfArray; i++) {
            if (arr[i] > max) {
                max2 = max;
                max = arr[i];
            } else if (arr[i] > max2 && arr[i] != max) {
                max2 = arr[i];
            }
        }
    
        if (max2 == INT_MIN) {
            max2 = -1;
        }
    
        return {max, max2};
    }
