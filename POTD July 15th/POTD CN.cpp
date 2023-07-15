// Sample Input 1 :
// 2
// 7
// 2
// Sample Output 1 :
// true
// false
// Explanation For Sample Input 1 :
// For test case 1 :
// We will print “true” because:
// We start with the input integer 7 and replace it with (7 * 7) = 49.
// The new number is 49, we replace it with (4 * 4) + (9 * 9) = 97.
// We replace this new number 97 with (9 * 9) + (7 * 7) = 130.
// We replace this new number 130 with (1 * 1) + (3 * 3) + (0 * 0) = 10.
// We replace this new number 10 with (1 * 1) + (0 * 0) = 1.
// Therefore, the original number 7 is a good number.

// For test case 2 : 
// We will print “false” because:
// If we start replacing the number 2 with the sum of the square of its digits then we will not be able to reach the number 1 even after infinite steps.
// Sample Input 2 :
// 2
// 1
// 1045
// Sample Output 2 :
// true
// false
bool isGoodNumber(int n) {
     unordered_set<int> seen;

    while (n != 1) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        if (seen.count(sum)) {
            return false;  // Found a cycle, not a good number
        }

        seen.insert(sum);
        n = sum;
    }

    return true;  // Reached 1, it is a good number
}
