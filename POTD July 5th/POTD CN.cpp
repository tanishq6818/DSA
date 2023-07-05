/*Sample Input 1:
2
4
22
Sample Output 1:
4
16
Explanation For Sample 1:
For the first test case, 4 itself is a power of two.
For the second test case, the nearest integer that is less than or equal to 22 and also is a power of two is 16.
Sample Input 2:
2
1
63
Sample Output 2:
1
32
Explanation For Sample 1:
For the first test case, 1 itself is a power of two.
For the second test case, the nearest integer that is less than or equal to 63 and also is a power of two is 32.*/

int greatestPowerOfTwo(int n) {
    int exponent = std::log2(n);
    int result = std::pow(2, exponent);
    return result;
}
