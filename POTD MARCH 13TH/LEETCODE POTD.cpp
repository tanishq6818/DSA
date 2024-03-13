Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
  class Solution {
public:
    int pivotInteger(int n) {
        // Iterate through possible pivot values
        for (int i = 1; i <= n; i++) {
            int sumLeft = 0;
            int sumRight = 0;

            // Calculate the sum of elements on the left side of the pivot
            for (int j = 1; j <= i; j++) {
                sumLeft += j;
            }

            // Calculate the sum of elements on the right side of the pivot
            for (int k = i; k <= n; k++) {
                sumRight += k;
            }

            // Check if the sums on both sides are equal
            if (sumLeft == sumRight) {
                return i; // Return the pivot value if found
            }
        }

        return -1; // Return -1 if no pivot is found
    }
};
