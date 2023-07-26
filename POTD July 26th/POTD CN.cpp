// Different Bits Sum Pairwise Sample Input 1 :
// 2
// 2
// 1 2
// 2
// 6 6
// Sample Output 1 :
// 4
// 0
// Explanation For Sample Input 1 :
// Test Case 1:
// All the possible pairs in the given array are:-
// f(1, 1) - as both numbers are same, no. of bit differences is 0
// f(1, 2) - 1 in binary is (0001) and 2 in binary is (0010). There are 2 bits which are different in both the numbers. Hence, no. of bit differences is 2.
// f(2, 2) - as both numbers are the same, no, of bit differences is 0
// f(2, 1) - same as (1, 2), hence no. of bit differences is 2.
// Summing the above values (0+2+0+2) we get 4. Hence, the output is 4.

// Test Case 2:
// There is only one possible pair (6,6). As both the numbers are sum, the output is 0.
// Sample Input 2 :
// 2
// 3 
// 1 3 5
// 4
// 4 6 7 8
// Sample Output 2 :
// 8
// 26

int differentBitsSumPairwise(vector<int> &arr, int n) {
    int result = 0;
    
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        for (int num : arr) {
            if (num & (1 << i))
                count++;
        }
        result += count * (n - count) * 2;
    }
    
    return result;
}
