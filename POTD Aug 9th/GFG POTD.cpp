long long int largestPrimeFactor(long long int N) {
        long long int maxPrime = -1;
    
        // Divide by 2 until it's no longer even
        while (N % 2 == 0) {
            maxPrime = 2;
            N /= 2;
        }
    
        // Now only odd factors are possible, so start from 3
        for (long long int i = 3; i * i <= N; i += 2) {
            while (N % i == 0) {
                maxPrime = i;
                N /= i;
            }
        }
    
        // If N is a prime greater than 2
        if (N > 2) {
            maxPrime = N;
        }
    
        return maxPrime;
    }
