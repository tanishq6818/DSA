const int MOD = 1000000007;
    int nthFibonacci(int n){
        // code here
        if (n <= 0) {
        return 0;
    }

    std::vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    return fib[n];
    }
