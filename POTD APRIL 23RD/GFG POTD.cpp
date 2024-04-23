Rohan has a special love for the matrices especially for the first element of the matrix. Being good at Mathematics, he also loves to solve the different problem on the matrices. So one day he started to multiply the matrix with the original matrix.  The elements of the original matrix a are given by [a00=1 , a01=1, a10=1, a11=0].
Given the power of the matrix, n calculate the an and return the a10 element mod 1000000007.

Example 1:

Input: 
n = 3
Output: 
2 
Explanation: Take the cube of the original matrix 
i.e a3 and the (a10)th element is 2.
Example 2:

Input: 
n = 4
Output: 
3
Explanation: Take the cube of the original matrix 
i.e a4 and the (a10)th element is 3.
Your Task:  
You dont need to read input or print anything. Complete the function firstElement() which takes n as input parameter and returns the a10 element mod 1000000007 of an.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<= n <=106

  const int MOD = 1000000007;

// Function to perform matrix multiplication
vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += (A[i][k] * B[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

// Function to calculate the power of the matrix
vector<vector<long long>> power(vector<vector<long long>>& A, int n) {
    if (n == 1) return A;

    vector<vector<long long>> half = power(A, n / 2);
    vector<vector<long long>> result = multiply(half, half);
    if (n % 2 == 1) {
        result = multiply(result, A);
    }
    return result;
}

int firstElement(int n) {
    // Define the original matrix
    vector<vector<long long>> original = {{1, 1}, {1, 0}};

    // Calculate the nth power of the matrix
    vector<vector<long long>> powerMatrix = power(original, n);

    // Return the a10 element mod 1000000007
    return powerMatrix[1][0] % MOD;
}
