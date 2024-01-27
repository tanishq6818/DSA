// Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
// As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

// NOTE:

// Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
// As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.
// Example 1:

// Input: 
// n = 5
// p[] = {40, 20, 30, 10, 30}
// Output: 
// True
// Explaination: 
// Let's divide this into matrix(only 4 are possible) 
// [ [40, 20] -> A
// , [20, 30] -> B
// , [30, 10] ->C
// , [10, 30] -> D ]
// First we perform multiplication of B & C -> (BC)
// then we multiply A to (BC) -> (A(BC))
// then we multiply D to (A(BC)) -> ((A(BC))D)
// so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
// Example 2:

// Input: 
// n = 3
// p = {3, 3, 3}
// Output: 
// True
// Explaination: 
// The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.

// Expected Time Complexity: O(n3)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 2 ≤ n ≤ 26 
// 1 ≤ p[i] ≤ 500 

string st;
    
    // Function to print the parenthesis of matrix chain multiplication
    void printParenthesis(int i, int j, int n, int *bracket, char &name){
        // If i and j are equal, it means only one matrix is remaining
        if (i == j){
            st += name; // add the name of matrix to the string
            name++; // increment the name for the next matrix
            return;
        }
        st += '('; // add '(' to the string
        printParenthesis(i, *((bracket+i*n)+j), n,bracket, name); // recursively print the parenthesis for the left side of the split
        printParenthesis(*((bracket+i*n)+j) + 1, j,n, bracket, name); // recursively print the parenthesis for the right side of the split
        st += ')'; // add ')' to the string
    }
    
    // Function to calculate the minimum number of operations needed to multiply the matrices
    string matrixChainOrder(int p[], int n)
    {
        int m[n][n]; // create a 2D array to store the minimum number of operations
        int bracket[n][n]; // create a 2D array to store the split position for each matrix multiplication
        for (int i = 1; i < n; i++)
            m[i][i] = 0; // initialize the diagonal elements to 0
        for (int L = 2; L < n; L++){ // iterate over the lengths of the sequences
            for (int i = 1; i < n-L+1; i++){ // iterate over the starting indices of the sequences
                int j = i + L - 1; // calculate the ending index of the sequence
                m[i][j] = INT_MAX; // set the minimum number of operations to a large value at first
                for (int k = i; k <= j-1; k++){ // iterate over possible split positions
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; // calculate the number of operations needed for this split
                    if (q < m[i][j]){ // if this split has less operations than the current minimum, update the values
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        char name = 'A'; // initialize the name of the matrices
        printParenthesis(1, n-1, n, (int *)bracket, name); // call the function to print the parenthesis
        return st; // return the string containing the parenthesis
    }
