// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.

// Example 1

// Input:
// X = abcd, Y = xycd
// Output: 6
// Explanation: Shortest Common Supersequence
// would be abxycd which is of length 6 and
// has both the strings as its subsequences.
// Example 2

// Input:
// X = efgh, Y = jghi
// Output: 6
// Explanation: Shortest Common Supersequence
// would be ejfghi which is of length 6 and
// has both the strings as its subsequences.
// Your Task:
// You don't have to take any input or print anything. Your task is to complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

// Expected Time Complexity: O(Length(X) * Length(Y)).
// Expected Auxiliary Space: O(Length(X) * Length(Y)).

// Constraints:
// 1<= |X|, |Y| <= 100

class Solution{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        //using dp[][] array to store length of LCS.
        int dp[1001][1001];
        
        //Following steps build dp[x+1][y+1] in bottom up fashion. Note that 
        //dp[i][j] contains length of LCS of s1[0..i-1] and s2[0..j-1].
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                //if i or j is 0, we mark dp[i][j] as 0.
                if(i==0||j==0)
                dp[i][j]=0;     
                
                //else if the current char in both strings are equal, we add 1 
                //to the output we got without including these both characters.
                else if (s1[i-1] == s2[j-1])        
                dp[i][j] = dp[i-1][j-1] + 1; 
                
                //else s1[i-1]!=s2[j-1] so we check the max output which 
                //comes from s1 or s2 without considering current character.
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        
        //returning the result.
        return dp[x][y];   
    }
    
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n){
        // Length of the shortest supersequence  = 
        // (Sum of lengths of given two strings) - (Length of LCS of two given strings)
        return ( m + n - lcs(m, n, X, Y) );
    }
};
