There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.



Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

Examples

Input: n = 1
Output: 10
Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)  
Input: n = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 25

long long getCount(int n) {
    if (n == 1) {
        return 10;  // There are 10 digits (0-9), each being a valid single-digit sequence
    }

    // Define the adjacent keys for each key in the keypad
    vector<vector<int>> moves = {
        {0, 8},       // 0
        {1, 2, 4},    // 1
        {2, 1, 3, 5}, // 2
        {3, 2, 6},    // 3
        {4, 1, 5, 7}, // 4
        {5, 2, 4, 6, 8}, // 5
        {6, 3, 5, 9}, // 6
        {7, 4, 8},    // 7
        {8, 0, 5, 7, 9}, // 8
        {9, 6, 8}     // 9
    };

    // Initialize the dp array with 0
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    
    // Base case: For sequences of length 1, each digit can be the end of exactly one sequence
    for (int j = 0; j < 10; ++j) {
        dp[1][j] = 1;
    }

    // Fill the dp array for sequences of length from 2 to n
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            dp[i][j] = 0;
            for (int k : moves[j]) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    // The result is the sum of all sequences of length n ending in any digit
    long long totalCount = 0;
    for (int j = 0; j < 10; ++j) {
        totalCount += dp[n][j];
    }

    return totalCount;
}
