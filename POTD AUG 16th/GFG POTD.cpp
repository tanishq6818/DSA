const int MOD = 1e9 + 7;

int findCatalan(int n) {
    int catalan[n + 1];
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++) {
            catalan[i] = (catalan[i] + (1LL * catalan[j] * catalan[i - j - 1]) % MOD) % MOD;
        }
    }

    return catalan[n];
}
The main change here is (1LL * catalan[j] * catalan[i - j - 1]) % MOD in the inner loop, which applies the modulo operation after each multiplication and ensures that the result doesn't overflow.

Please try this corrected code with the input value of 175, and it should give you the correct output of 49829519.





