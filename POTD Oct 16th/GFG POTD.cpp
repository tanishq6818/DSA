// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. A group of connected 1s forms an island. Two 1s are connected if they share one of their sides with each other.

// Return the size of the largest island in the grid after applying this operation.

// Example 1:

// Input: 
// grid = [[1,0],[0,1]]
// Output:
// 3
// Explanation:
// Change any one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: 
// grid = [[1,1],[1,0]]
// Output:
// 4
// Explanation:
// Change the only 0 to 1 and make the island bigger, then we get an island with area = 4.
// Example 3:

// Input: 
// grid = [[1,1],[1,1]]
// Output:
// 4
// Explanation:
// Can't change any 0 to 1, only one island possible with area = 4.
// Your Task:

// You don't have to read input or print anything. You have to complete the functions largestIsland(), which takes binary matrix as input and returns an integer denoting the size of the largest island in grid after applying the operation.

// Constraints:

// 1 <= n <= 500
// 0 <= grid[i][j] <= 1 (grid[i][j] ∈ {0, 1} and 0<=i,j<n)

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return 0;
        grid[i][j]=index;
        int count = dfs(grid, i+1, j, index) + 
                    dfs(grid, i-1, j, index) + 
                    dfs(grid, i, j+1, index) + 
                    dfs(grid, i, j-1, index);
        return count+1;
    }
    
    void findNeighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
		//finding adjacent island groups
        int n=grid.size();
        if(i>0) s.insert(grid[i-1][j]);
        if(j>0) s.insert(grid[i][j-1]);
        if(i<n-1) s.insert(grid[i+1][j]);
        if(j<n-1) s.insert(grid[i][j+1]);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), res=0, index=2, count;
        map<int, int> area;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    area[index]=dfs(grid, i, j, index);
                    res=max(res, area[index++]);
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    set<int> s;
                    findNeighbours(grid, i, j, s);
                    count=1;   
                    for(int i:s)
                        count+=area[i];     
                    res=max(res, count);
                }
            }
        }
        
        return res;
    }
};
