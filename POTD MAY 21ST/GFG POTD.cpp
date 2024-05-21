// Given a sorted array of unique elements in increasing order, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
// Keep the following points in mind:

// If x is present in the array, then it need not be considered.
// If two elements have the same difference as x, the greater element is prioritized.
// If sufficient elements are not present on the right side, take elements from the left and vice versa.
 
// Example 1:

// Input:
// n = 13
// arr[] = {12, 16, 22, 30, 35, 39, 42, 
//          45, 48, 50, 53, 55, 56}
// k = 4, x = 35
// Output: 39 30 42 45
// Explanation: 
// First closest element to 35 is 39.
// Second closest element to 35 is 30.
// Third closest element to 35 is 42.
// And fourth closest element to 35 is 45.

// Example 2:

// Input:
// n = 5
// arr[] = {1, 2, 3, 6, 10}
// k = 3, x = 4
// Output: 3 6 2
// Explanation: 
// First closest element is 3.
// There are two elements 2 and 6 for which 
// the difference with 4 is same i.e. 2.
// So first take greatest number 6 
// then the lower number 2.

// Your Task:
// You don't need to read input or print anything. Complete the function printKClosest() which takes arr[], n, k, and x as input parameters and returns an array of integers containing the K closest elements to x in arr[].


// Expected Time Complexity: O(log n + k)
// Expected Auxiliary Space: O(k)


// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ k ≤ n
// 1 ≤ x ≤ 106
// 1 ≤ arr[i] ≤ 106

 class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> result;
        vector<int> closest;

        // Function to find the index where the array changes from values smaller to
        // values greater than x
        int l = findCrossOver(arr, 0, n - 1, x);

        int r = l + 1; // Set r as the next index
        int count = 0; // Counter for the number of closest values found

        if (arr[l] == x) { // If the value at l is equal to x, move l to the left
            l--;
        }

        // Compare the values at index l and r and select the closest value until k
        // closest values are found
        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] < arr[r] - x) {
                closest.push_back(arr[l]);
                l--;
            } else {
                closest.push_back(arr[r]);
                r++;
            }
            count++;
        }

        // If k closest values are not found but there are still values to the left of l
        while (count < k && l >= 0) {
            closest.push_back(arr[l]);
            l--;
            count++;
        }

        // If k closest values are not found but there are still values to the right of
        // r
        while (count < k && r < n) {
            closest.push_back(arr[r]);
            r++;
            count++;
        }

        // Copy closest values to result vector
        for (int i = 0; i < k; i++) {
            result.push_back(closest[i]);
        }

        return result;
    }

  private:
    // Function to find the index where array changes from values smaller to values
    // greater than x
    int findCrossOver(vector<int>& arr, int low, int high, int x) {
        if (arr[high] <= x) {
            return high;
        }
        if (arr[low] > x) {
            return low;
        }
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        return findCrossOver(arr, low, mid - 1, x);
    }
};
