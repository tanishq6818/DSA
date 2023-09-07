// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// Example 1:

// Input:
// arr[] = {2, 5, 7}
// start = 3, end = 30
// Output:
// 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30
// Example 2:

// Input:
// arr[] = {3, 4, 65}
// start = 7, end = 66175
// Output:
// 4
// Explanation:
// Step 1: 7*3 = 21 % 100000 = 21 
// Step 2: 21*3 = 63 % 100000 = 63 
// Step 3: 63*65 = 4095 % 100000 = 4095 
// Step 4: 4095*65 = 266175 % 100000 = 66175
// Your Task:
// You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

// Expected Time Complexity: O(105)
// Expected Space Complexity: O(105)

// Constraints:

// 1 <= n <= 104
// 1 <= arr[i] <= 104
// 1 <= start, end < 105
// Back-end complete function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // array which stores the minimum steps
        // to reach i from start
        int ans[100001];

        // -1 indicated the state has not been visited
        memset(ans, -1, sizeof(ans));
        const int mod = 100000;

        // queue to store all possible states
        queue<int> q;

        // initially push the start
        q.push(start % mod);

        // to reach start we require 0 steps
        ans[start] = 0;

        // till all states are visited
        while (!q.empty()) {

            // get the topmost element in the queue
            int top = q.front();

            // pop the topmost element
            q.pop();

            // if the topmost element is end
            if (top == end) return ans[end];

            // perform multiplication with all array elements
            for (int i = 0; i < arr.size(); i++) {
                int pushed = top * arr[i];
                pushed = pushed % mod;

                // if not visited, then push it to queue
                if (ans[pushed] == -1) {
                    ans[pushed] = ans[top] + 1;
                    q.push(pushed);
                }
            }
        }

        return -1;
    }
};
