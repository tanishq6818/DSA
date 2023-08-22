// Function to calculate (x^y) % p
int power(int x, int y, int p) {
    int result = 1;
    x = x % p;  // Take modulo of base if it is more than or equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            result = (result * x) % p;

        // y must be even now
        y = y >> 1; // y = y / 2
        x = (x * x) % p;
    }
    return result;
}

int boringFactorials(int n, int p) {
    if (n >= p)
        return 0;  // n! % p is 0 if n >= p

    int result = p - 1; // Initialize result as (p-1)
    for (int i = n + 1; i < p; ++i)
        result = (result * power(i, p - 2, p)) % p;

    return result;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;
        cout << boringFactorials(n, p) << endl;
    }

    return 0;
}





