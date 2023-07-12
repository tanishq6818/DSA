int CountSumConsecutiveNums(int n) 
{
    // Write your code here.
    int count = 0;
    for (int i = 1; i <= n / 2; i++) {
        int sum = i;
        for (int j = i + 1; sum <= n; j++) {
            if (sum == n) {
                count++;
                break;
            }
            sum += j;
        }
    }
    return count;
}
//optimized 

#include <cmath>

int CountSumConsecutiveNums(int n) {
    int count = 0;
    int limit = (int)sqrt(2 * n);

    for (int i = 1; i <= limit; i++) {
        int numerator = n - (i * (i - 1)) / 2;
        int denominator = i;

        if (numerator % denominator == 0) {
            count++;
        }
    }

    return count-1;
}
