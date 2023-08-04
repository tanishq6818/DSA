// Problem Statement

// You are given two integers 'N' and 'M' A pair (x, y) is a divisible pair if it satisfies the

// following conditions

// o) 1 <= x <= 'N'

// b) 1 <= y <= 'M' c) x + y is divisible by 5

// Your task is to return the count of all divisible pairs that can be formed from given

// 'N' and 'M

// Example:

// 11 N-3 and N-5, then (x1,y-4), (x-3). [**

// 3, y2) are the pairs that satisfy the given conditions. Sample Input 1 :
// 2
// 1 5
// 2 3
// Sample Output 1 :
// 1
// 1
// Explanation Of Sample Output 1 :
// For test case 1 :
// Only (1,4) satisfy the given condition.

// For test case 2 :
// Only (2,3) satisfy the given conditions.
// Sample Input 2 :
// 2
// 1 3
// 6 12
// Sample Output 2 :
// 0
// 14 

int countOfDivisiblePairs(int n, int m) {
    int count = 0;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if ((x + y) % 5 == 0) {
                count++;
            }
        }
    }

    return count;
}

