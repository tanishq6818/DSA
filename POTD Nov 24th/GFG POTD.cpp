// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
// The elements can be large so return it modulo 109 + 7.

// File:PascalTriangleAnimated2.gif

// Example 1:

// Input:
// N = 4
// Output: 
// 1 3 3 1
// Explanation: 
// 4th row of pascal's triangle is 1 3 3 1.
// Example 2:

// Input:
// N = 5
// Output: 
// 1 4 6 4 1
// Explanation: 
// 5th row of pascal's triangle is 1 4 6 4 1.
// Your Task:
// Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 103

 vector<long long> nthRowOfPascalTriangle(int n) {

        // Base case: if n=1, return [1]
        if(n==1)
        {
            vector<long long> tmp;
            tmp.push_back(1ll);
            return tmp;
        }

        // Recursive call to generate the (n-1)th row of Pascal's Triangle
        vector<long long> tans = nthRowOfPascalTriangle(n-1);

        // Create a vector to store the current row of Pascal's Triangle
        vector<long long> ans;
        ans.push_back(1);

        // Generate the current row by summing consecutive elements from the (n-1)th row
        for(int i=1;i<tans.size();i++)
            ans.push_back((tans[i]+tans[i-1])%1000000007);

        ans.push_back(1); // Add 1 at the end of the current row
        return ans; // Return the current row of Pascal's Triangle
    }
