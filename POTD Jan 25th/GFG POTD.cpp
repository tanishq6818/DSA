// You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

// Example 1:

// Input:
// Num1 = 1033 
// Num2 = 8179
// Output: 6
// Explanation:
// 1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
// There are only 6 steps reuired to reach Num2 from Num1. 
// and all the intermediate numbers are 4 digit prime numbers.
// Example 2:

// Input:
// Num1 = 1033 
// Num2 = 1033
// Output:
// 0
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1000<=Num1,Num2<=9999
// Num1 and Num2 are prime numbers.

class Solution{   
public:
    int mxp;
    vector<int> prime;
    Solution()
    {
      mxp=9999;
      prime=vector<int>(10001,1);
      prime[1]=0;
      //Seive Of Eratosthenes
      for(int i=2;i<=mxp;i++)
      {
        if(prime[i])
        {
          for(int j=2;j*i<=mxp;j++)
            prime[j*i]=0;
        }
      }
    } 

    int bfs(int source,int &destination)
    {
      vector<int> dp(10001,-1); //stores the shotest distance from source to destination
      vector<int> vis(10001); 
      queue<int> q;
      q.push(source);
      dp[source]=0;
      vis[source]=0;
      while(!q.empty())
      {
        int current=q.front();
        q.pop();
        if(vis[current])
          continue;
        vis[current]=1;
        string s=to_string(current);
        for(int i=0;i<4;i++)
        {
          for(char ch='0';ch<='9';ch++)
          {
            if(ch==s[i]||(ch=='0'&&i==0))
              continue;
            string nxt=s;
            nxt[i]=ch;
            int nxtN=stoi(nxt);
            if(prime[nxtN]&&dp[nxtN]==-1)
            {
              dp[nxtN]=1+dp[current];
              q.push(nxtN);
            }
          }
        }
      }
      return dp[destination];
    }
    
    int solve(int Num1,int Num2)
    {   
      return bfs(Num1,Num2);
    }
};
