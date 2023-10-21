// The problem is to count all the possible paths from top left to bottom right of an MxN matrix with the constraints that from each cell you can either move to right or down.

// Return answer modulo 109+7.

// Example 1:

// Input:
// M = 3 and N = 3
// Output: 6
// Explanation:
// Let the given input 3*3 matrix is filled 
// as such:
// A B C
// D E F
// G H I
// The possible paths which exists to reach 
// 'I' from 'A' following above conditions 
// are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
// ADEHI, ABEFI
// Example 2:

// Input:
// M = 1 and N = 4
// Output: 1
// Explanation:
// There is only one direction to go in,
// and thus, there is only one path possible.
// Your Task
// You don't need to read input or print anything. Your task is to complete the function numberOfPaths() which takes the integer M and integer N as input parameters and returns an integer, the number of paths.

// Expected Time Complexity: O(M)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ N ≤ 108
// 1 ≤ M ≤ 1054

long long numberOfPaths(int M, int N) {
    // Initialize variables to store the result
    const int MOD = 1000000007; // 10^9 + 7
    long long result = 1;

    // Calculate the result using the combinatorial formula (M-1 + N-1) choose (M-1)
    // This can be computed using a loop to avoid overflow
    for (int i = 1; i <= min(M - 1, N - 1); i++) {
        result = (result * (M + N - 2 - i + 1)) % MOD;
        result = (result * modInverse(i, MOD)) % MOD;
    }

    return result;
}

// Function to calculate the modular inverse
long long modInverse(long long a, long long m) {
    long long m0 = m;
    long long x0 = 0, x1 = 1;

    while (a > 1) {
        long long q = a / m;
        long long t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}
