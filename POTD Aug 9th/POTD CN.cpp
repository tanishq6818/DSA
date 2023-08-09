#include <bits/stdc++.h> 
int minChanges(int n, int m, vector<vector<char>> &matrix){
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i + 1 < n){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (matrix[i][j] != 'D'));
            }
            if(j + 1 < m){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (matrix[i][j] != 'R'));
            }
        }
    }
    return dp[n - 1][m - 1];
}
