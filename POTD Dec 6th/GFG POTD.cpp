// Given two integers L, R, and digit X. Find the number of occurrences of X in all the numbers in the range (L, R) excluding L and R.

// Example 1:

// Input:
// L=10, R=19, X=1
// Output:
// 9
// Explanation:
// There are 9 1s (11, 12, 13, 14, 15, 16, 17, 18) in the numbers in the range (10,19).
// Example 2:

// Input:
// L=18, R=81, X=9
// Output:
// 7
// Explanation:
// There are 7 occurrences of the digit 9 in the numbers in the range (18,81).
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countX() which takes three integers L, R, and X as input parameters and returns the number of occurrences of X in the numbers in the range(L, R).

// Expected Time Complexity:O(RLogR)
// Expected Auxillary Space:O(1)

// Constraints:
// 1 <= L< R <= 105
// 0 <= X <= 9 


class Solution {
  public:
    // Function to count the occurrences of X in a number N.
    int count(int N, int X) {
        int ans = 0;
        while (N) {
            // Checking if the last digit of N is X and incrementing ans if true.
            if (N % 10 == X) ans++;
            // Removing the last digit of N.
            N /= 10;
        }
        // Returning the count of occurrences of X in N.
        return ans;
    }
    // Function to count the occurrences of X in the range from L+1 to R-1.
    int countX(int L, int R, int X) {
        int ans = 0;
        // Iterating over the numbers in the range.
        for (int i = L + 1; i < R; i++) {
            // Computing the count of occurrences of X in each number and adding to ans.
            ans += count(i, X);
        }
        // Returning the total count of occurrences of X in the range.
        return ans;
    }
};
