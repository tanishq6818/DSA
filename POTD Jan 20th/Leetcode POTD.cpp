// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104


const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        std::stack<int> st; // Stack to store indices

        // Arrays to store the previous and next smaller elements for each element in arr
        std::vector<int> prevSmaller(n, -1);
        std::vector<int> nextSmaller(n, n);

        // Fill the prevSmaller array
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }

        // Clear the stack for the next iteration
        while (!st.empty()) {
            st.pop();
        }

        // Fill the nextSmaller array
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }

        // Calculate the sum of min(b) for each subarray
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int contribution = (i - prevSmaller[i]) * (nextSmaller[i] - i);
            result = (result + static_cast<long long>(arr[i]) * contribution) % MOD;
        }

        return static_cast<int>(result);
    }
};
