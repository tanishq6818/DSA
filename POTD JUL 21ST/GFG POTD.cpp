Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 2 * 104
-10 <= arr[i] <= 10
  long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            // Only 1 element in the array.
            return arr[0];
        }

        long long int ans = 1;
        int mod = 1e9 + 7;
        int id = -1, minElement = 0;
        int zeroCount = 0, negCount = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                // Counting number of zeros.
                zeroCount++;
            } else if (arr[i] < 0) {
                // Counting number of negative numbers.
                negCount++;
                if (id == -1 || arr[i] > minElement) {
                    // Storing the index of negative element having least magnitude.
                    id = i;
                    minElement = arr[i];
                }
            }
        }
        if (zeroCount == n) {
            // If there are all zeros.
            return 0;
        }
        if (negCount == 1 && zeroCount == n - 1) {
            // If all elements are zero except one negative element, then return 0.
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                continue;
            }
            if (negCount % 2 == 1 && i == id) {
                // Removing the negative element having least magnitude.
                continue;
            }
            ans = ((ans * arr[i]) % mod + mod) % mod;
        }
        return ans;
    }
