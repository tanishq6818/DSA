Given two strings x and y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

Example 1:

Input: x = "abcd", y = "acdb", costX = 10 
       costY = 20.
Output: 30
Explanation: For Making both strings 
identical we have to delete character 
'b' from both the string, hence cost 
will be = 10 + 20 = 30.
Example 2:

Input : x = "ef", y = "gh", costX = 10
        costY = 20.
Output: 60
Explanation: For making both strings 
identical, we have to delete 2-2 
characters from both the strings, hence 
cost will be = 10 + 10 + 20 + 20 = 60.
Your Task:
You don't need to read or print anything. Your task is to complete the function findMinCost() which takes both strings and the costs as input parameters and returns the minimum cost.

Expected Time Complexity: O(|x|*|y|)
Expected Space Complexity: O(|x|*|y|)

Constraints:
1 ≤ |x|, |y| ≤ 1000
1<= costX, costY <= 105

  int lcs(string X, string Y, int m, int n) {
        int L[m + 1][n + 1];

        /* Following steps build L[m+1][n+1] in bottom
           up fashion. Note that L[i][j] contains length
           of LCS of X[0..i-1] and Y[0..j-1] */
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;

                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        /* L[m][n] contains length of LCS for X[0..n-1] and
           Y[0..m-1] */
        return L[m][n];
    }

    // Returns cost of making X[] and Y[] identical.  costX is
    // cost of removing a character from X[] and costY is cost
    // of removing a character from Y[]/
    int findMinCost(string X, string Y, int costX, int costY) {
        // Find LCS of X[] and Y[]
        int m = X.length(), n = Y.length();
        int len_LCS = lcs(X, Y, m, n);

        // Cost of making two strings identical is SUM of
        // following two
        //   1) Cost of removing extra characters
        //      from first string
        //   2) Cost of removing extra characters from
        //      second string
        return costX * (m - len_LCS) + costY * (n - len_LCS);
    }
