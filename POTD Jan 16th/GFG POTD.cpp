// Given two integers m and n, try making a special sequence of numbers seq of length n such that

// seqi+1 >= 2*seqi 
// seqi > 0
// seqi <= m
// Your task is to determine total number of such special sequences possible.

// Example 1:

// Input: 
// m = 10
// n = 4
// Output: 
// 4
// Explaination: 
// There should be n elements and 
// value of last element should be at-most m. 
// The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
// {1, 2, 4, 10}, {1, 2, 5, 10}.
// Example 2:

// Input: 
// m = 5
// n = 2
// Output: 
// 6
// Explaination: 
// The sequences are {1, 2}, 
// {1, 3}, {1, 4}, {1, 5}, {2, 4}, {2, 5}.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function numberSequence() which takes the number m and n as input parameters and returns the number of possible special sequences.

// Expected Time Complexity: O(m*n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ m, n ≤ 100

 int numberSequence(int m, int n)
    {

        int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                // Base case : If length of sequence is 0
                // or maximum value is 0, there cannot
                // exist any special sequence
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                // if length of sequence is more than
                // the maximum value, special sequence
                // cannot exist
                else if (i < j)
                    dp[i][j] = 0;

                // If length of sequence is 1 then the
                // number of special sequences is equal
                // to the maximum value
                // For example with maximum value 2 and
                // length 1, there can be 2 special
                // sequences {1}, {2}
                else if (j == 1)
                    dp[i][j] = i;

                // otherwise calculate
                else
                    dp[i][j]
                        = dp[i - 1][j] + dp[i / 2][j - 1];
            }
        }
        return dp[m][n];
    }
