// A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. Given a square matrix of size NxN. Find the minimum number of operation(s) that are required to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.
// Example 1:

// Input:
// N = 2
// matrix[][] = {{1, 2},
//               {3, 4}}
// Output: 
// 4
// Explanation:
// Updated matrix:
// 4 3
// 3 4
// 1. Increment value of cell(0, 0) by 3
// 2. Increment value of cell(0, 1) by 1
// Hence total 4 operation are required.
// Example 2:

// Input:
// N = 3
// matrix[][] = {{1, 2, 3},
//               {4, 2, 3},
//               {3, 2, 1}}
// Output: 
// 6
// Explanation:
// Number of operations applied on each cell are as follows:
// 1 2 0
// 0 0 0
// 0 1 2
// Such that all rows and columns have sum of 9.
// Your Task: 
// You don't need to read input or print anything. Complete the function findMinOpeartion() that takes matrix and n as input parameters and returns the minimum number of operations.

// Expected Time Complexity: O(N * N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 103
// 1 <= matrix[i][j] <= 106


int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> sumRow(n,0);
        vector<int> sumCol(n,0);
        
        //calculating sumRow[] and sumCol[] array.
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sumRow[i] += matrix[i][j];
                sumCol[j] += matrix[i][j];
            }
        }
                
        //finding maximum sum value in either row or in column.
        int maxSum = 0;
        for (int i = 0; i < n; ++i)
        {
            maxSum = max(maxSum, sumRow[i]);
            maxSum = max(maxSum, sumCol[i]);
        }
        
        int count = 0;
        for (int i = 0, j = 0; i < n && j < n;) 
        {
            //finding minimum increment required in either row or column.
            int diff = min(maxSum - sumRow[i],  maxSum - sumCol[j]);
            
            //adding difference in corresponding cell,
            //sumRow[] and sumCol[] array.
            matrix[i][j] += diff;
            sumRow[i] += diff;
            sumCol[j] += diff;
            
            //updating the result.
            count += diff;
            
            //if ith row is satisfied, incrementing i for next iteration.
            if (sumRow[i] == maxSum)
                ++i;
            
            //if jth column is satisfied, incrementing j for next iteration.
            if (sumCol[j] == maxSum)
                ++j;
        }
        //returning the result.
        return count;
    } 
