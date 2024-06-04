Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since the number can be very large, return the answer after modulo with 1e9+7.

Example 1:

Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Example 2:

Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111.  The strings with consecutive 1's are 011, 110 and 111.
Example 3:

Input: n = 5
Output: 19
Explanation: There are 19 strings having consecutive 1's.
Your Task:
You don't need to read input or print anything. Your task is to complete the function numberOfConsecutiveOnes() which takes an integer n and returns the number of binary strings that contain consecutive 1s in them.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints
2 <= n <= 105

// Function to calculate power with modulo
    long long power(long long a, long long b, long long mod) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return ans;
    }

    // Function to calculate the number of binary strings without consecutive ones
    int numberOfConsecutiveOnes(int n) {

        int a[n], b[n];
        a[0] = b[0] = 1;
        long long mod = 1e9 + 7;
        // Generating the count of strings ending with 0 and strings ending with 1
        for (int i = 1; i < n; i++) {
            a[i] = (a[i - 1] + b[i - 1]) % mod;
            b[i] = a[i - 1];
        }

        // Subtracting the count of strings with consecutive ones from 2^N
        return (power(2, n, mod) + mod - (a[n - 1] + b[n - 1]) % mod) % mod;
    }
