// Given a boolean expression s of length n with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer can be large, so return it with modulo 1003

// Example 1:

// Input: 
// n = 7
// s = T|T&F^T
// Output: 
// 4
// Explaination: 
// The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
// Example 2:

// Input: 
// n = 5
// s = T^F|F
// Output: 
// 2
// Explaination: 
// ((T^F)|F) and (T^(F|F)) are the only ways.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function countWays() which takes n and s as input parameters and returns number of possible ways modulo 1003.

// Expected Time Complexity: O(n3)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 ≤ n ≤ 200 

int countWaysUtil(string& s, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp) {
    // Base case: if the expression has only one symbol
    if (i == j) {
        if (isTrue)
            return s[i] == 'T' ? 1 : 0;
        else
            return s[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ways = 0;
    for (int k = i + 1; k < j; k += 2) {
        int leftTrue = countWaysUtil(s, i, k - 1, true, dp);
        int leftFalse = countWaysUtil(s, i, k - 1, false, dp);
        int rightTrue = countWaysUtil(s, k + 1, j, true, dp);
        int rightFalse = countWaysUtil(s, k + 1, j, false, dp);

        if (s[k] == '&') {
            if (isTrue)
                ways += (leftTrue * rightTrue) % 1003;
            else
                ways += ((leftFalse * rightTrue) % 1003 + (leftTrue * rightFalse) % 1003 + (leftFalse * rightFalse) % 1003) % 1003;
        } else if (s[k] == '|') {
            if (isTrue)
                ways += ((leftTrue * rightTrue) % 1003 + (leftFalse * rightTrue) % 1003 + (leftTrue * rightFalse) % 1003) % 1003;
            else
                ways += (leftFalse * rightFalse) % 1003;
        } else if (s[k] == '^') {
            if (isTrue)
                ways += ((leftTrue * rightFalse) % 1003 + (leftFalse * rightTrue) % 1003) % 1003;
            else
                ways += ((leftTrue * rightTrue) % 1003 + (leftFalse * rightFalse) % 1003) % 1003;
        }
    }

    return dp[i][j][isTrue] = ways % 1003;
}

int countWays(int n, string s) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return countWaysUtil(s, 0, n - 1, true, dp);
}
