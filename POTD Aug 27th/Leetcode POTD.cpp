// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

// Example 1:

// Input: stones = [0,1,3,5,6,8,12,17]
// Output: true
// Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
// Example 2:

// Input: stones = [0,1,2,3,4,8,9,11]
// Output: false
// Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

class Solution {
public:
    unordered_map<int, int> mark;
    int dp[2001][2001];
    
    int solve(vector<int>& stones, int n, int index, int prevJump) {
        // If reached the last stone, return 1.
        if (index == n - 1) {
            return 1;
        }
        
        // If this subproblem has been already calculated, return it.
        if (dp[index][prevJump] != -1) {
            return dp[index][prevJump];  
        }
        
        int ans = false;
        // Iterate over the three possibilities {k - 1, k, k + 1}.
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0 && mark.find(stones[index] + nextJump) != mark.end()) {
                ans = ans || solve(stones, n, mark[stones[index] + nextJump], nextJump);
            }
        }

        // Store the result to fetch later.
        return dp[index][prevJump] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        // Mark stones in the map to identify if such stone exists or not.
        for (int i = 0 ; i < stones.size(); i++) {
            mark.insert({stones[i], i});
        }
        
        // Mark all states as -1 to denote they're not calculated.
        memset(dp, -1, sizeof(dp));
        return solve(stones, stones.size(), 0, 0);
    }
};
