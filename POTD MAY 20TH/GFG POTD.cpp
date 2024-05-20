// Implement pow(x, n) % M.
// In other words, for a given value of x, n, and M, find  (xn) % M.
 

// Example 1:

// Input:
// x = 3, n = 2, m = 4
// Output:
// 1
// Explanation:
// 32 = 9. 9 % 4 = 1.
// Example 2:

// Input:
// x = 2, n = 6, m = 10
// Output:
// 4
// Explanation:
// 26 = 64. 64 % 10 = 4.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n, and M as input parameters and returns xn % M.
 

// Expected Time Complexity: O(log(n))
// Expected Space Complexity: O(1)
 

// Constraints:
// 1 ≤ x, n, M ≤ 109
long long int PowMod(long long int x, long long int n, long long int M) {
    long long int result = 1;
    x = x % M; // To handle the case when x >= M

    while (n > 0) {
        // If n is odd, multiply x with the result
        if (n % 2 == 1) {
            result = (result * x) % M;
        }
        // n must be even now
        n = n >> 1; // n = n / 2
        x = (x * x) % M; // Change x to x^2
    }
    return result;
}
