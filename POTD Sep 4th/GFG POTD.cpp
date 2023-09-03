// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Example 1:

// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix. 
// Example 2:

 

// Input: 
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500

// Back-end complete function Template for C++
// class Solution{
// public:
//      vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
//         vector<vector<char>> ans(mat);

//         // Helper function to check if 'O' is surrounded by 'X'
//         auto isSurrounded = [&](int i, int j) {
//             return i > 0 && i < n - 1 && j > 0 && j < m - 1 &&
//                   mat[i - 1][j] == 'X' && mat[i + 1][j] == 'X' &&
//                   mat[i][j - 1] == 'X' && mat[i][j + 1] == 'X';
//         };

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (mat[i][j] == 'O' && isSurrounded(i, j)) {
//                     ans[i][j] = 'X';
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution{
public:
    int N, M;
    void floodFillUtil(vector<vector<char>> &screen, int x, int y, 
                        char prevC, char newC)
    {
        // Base cases
        if (x < 0 || x >= N || y < 0 || y >= M)
            return;
        if (screen[x][y] != prevC)
            return;
        // Replace the color at (x, y)
        screen[x][y] = newC;
        floodFillUtil(screen, x+1, y, prevC, newC);
        floodFillUtil(screen, x-1, y, prevC, newC);
        floodFillUtil(screen, x, y+1, prevC, newC);
        floodFillUtil(screen, x, y-1, prevC, newC);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        N = n;
        M = m;
        vector<vector<char>> temp = mat;
        for(int i = 0;i < n;i++)
		    for(int j = 0;j < m;j++)
		        if(temp[i][j] == 'O')
		            temp[i][j] = '-';
		
		for(int i = 0;i < n;i++)
			if(temp[i][0] == '-')
			    floodFillUtil(temp, i, 0, '-', 'O');
		
		for(int i = 0;i < n;i++)
			if(temp[i][m-1] == '-')
			    floodFillUtil(temp, i, m-1, '-', 'O');
			
		for(int i = 0;i < m;i++)
			if(temp[0][i] == '-')
			    floodFillUtil(temp, 0, i, '-', 'O');
			
		for(int i = 0;i < m;i++)
			if(temp[n-1][i] == '-')
			    floodFillUtil(temp, n-1, i, '-', 'O');
		
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				if(temp[i][j] == '-')
				    temp[i][j] = 'X';
	    return temp;
    }
};
