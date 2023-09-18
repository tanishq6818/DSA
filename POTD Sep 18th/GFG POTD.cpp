bool isPowerofTwo(long long n){
        
        // Your code here   
        if (n <= 0) {
            return false;  // Negative numbers and zero cannot be powers of 2
        }
        
        return (n & (n - 1)) == 0;
        
    }
