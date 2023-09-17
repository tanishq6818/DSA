vector<long long> printFibb(int n) {
    std::vector<long long> fib_list;

    // Initialize the first two Fibonacci numbers
    long long a = 1, b = 1;

    // Special case for n = 1
    if (n >= 1) {
        fib_list.push_back(a);
    }

    // Special case for n = 2
    if (n >= 2) {
        fib_list.push_back(b);
    }

    // Generate the remaining Fibonacci numbers
    for (int i = 2; i < n; i++) {
        long long next_fib = a + b;
        fib_list.push_back(next_fib);
        a = b;
        b = next_fib;
    }

    return fib_list;}





