// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

int longestPairChain(int i, vector<vector<int>>& pairs, int& n, vector<int>& memo) {
        if (memo[i] != 0) {
            return memo[i];
        }
        memo[i] = 1;
        for (int j = i + 1; j < n; i++) {
            if (pairs[i][1] < pairs[j][0]) {
                memo[i] = max(memo[i], 1 + longestPairChain(j, pairs, n, memo));
            }
        }
        return memo[i];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> memo(n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, longestPairChain(i, pairs, n, memo));
        }
        return ans;
    }
