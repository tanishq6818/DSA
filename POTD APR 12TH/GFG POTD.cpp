Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.

Example 1:

Input:
n = 3
arr = {5, 10, 15}
Output:
15
Explanation:
The bitwise Ands of all pairs where i<j are (5&10) = 0, (5&15) = 5 and (10&15) = 10.
Therefore, the total sum = (0+5+10) = 15.
Example 2:

Input:
n = 4
arr = {10, 20, 30, 40}
Output:
46
Explanation:
The sum of bitwise Ands 
of all pairs = (0+10+8+20+0+8) = 46.
Your Task:
You don't need to read input or print anything.Your Task is to complete the function pairAndSum() which takes an Integer n and an array arr[]  of size n as input parameters and returns the sum of bitwise Ands of all pairs.

Expected Time Complexity:O(n)
Expected Auxillary Space:O(1)

Constraints:
1 <= n <= 105
1 <= arr[i] <= 108

long long pairAndSum(int n, long long arr[]) {
    long long total_sum = 0;

    // We need to check up to 27 bits since the maximum value can be up to 10^8
    for (int bit = 0; bit < 27; bit++) {
        long long count_1 = 0;

        // Calculate how many numbers have the current bit set
        for (int i = 0; i < n; i++) {
            if (arr[i] & (1LL << bit)) {
                count_1++;
            }
        }

        // Each pair where both numbers have this bit set contributes 2^bit to the sum
        long long bit_value = 1LL << bit;
        long long pairs = count_1 * (count_1 - 1) / 2;  // Count of pairs where both have this bit set
        total_sum += pairs * bit_value;
    }

    return total_sum;
}
