// Problem Statement

// You are given an array of 'N' integers. You need to return another array 'product' such that 'product' contains the product of all the arrays except the element of the ith position in the given array. Note

// As the product of elements can be very large you need to return the answer in mod (109+7).

// Follow Up

// Try to do this without using the division operator '/', in constant space. The output array does not count as extra space for the purpose of space complexity analysis.

// Detailed explanation (Input/output format. Notes, in

// Constraints:

// 1 <= T <= 10^2

// 2 <= N<= 10^4

// 1 <= A[i] <= 10^9

// Where 'T' is the number of test cases, 'N' is

// the size of the array, 'A[i]' is the size of

// the array elements.
// Sample Input 1:
// 2
// 5 
// 1 3 3 10 2
// 6 
// 2 4 6 3 1 1
// Sample Output 1:
// 180 60 60 18 90
// 72 36 24 48 144 144
// Explanation For Sample Input 1:
// Test case 1:
// Product of elements except 1 = 3 * 3 * 10 * 2 = 180       
// Product of elements except 3 = 1  * 3 * 10 * 2 = 60       
// Product of elements except 3 = 1 * 3  * 10 * 2 = 60       
// Product of elements except 10 = 1 * 3 * 3 * 2 = 18       
// Product of elements except 2 = 1 * 3 * 3 * 10 = 90       

// Test case 2:
// Product of elements except 2 = 4 * 6 * 3 * 1 * 1 = 72   
// Product of elements except 4 = 2 * 6 * 3 * 1 * 1 = 36   
// Product of elements except 6 = 2 * 4 * 3 * 1 * 1 = 24   
// Product of elements except 3 = 2 * 4 * 6 * 1 * 1 = 48  
// Product of elements except 1 = 2 * 4 * 6 * 1 * 1 = 144   
// Product of elements except 1 = 2 * 4 * 6 * 3 * 1 = 144  
// Sample Input 2:
// 2
// 5 
// 1 10 1 2 2
// 6
// 2 12 1 1 20 1 
// Sample Output 2:
// 40 4 40 20 20
// 240 40 480 480 24 480
// Explanation For Sample Input 2:
// Test case 1:
// Product of elements except 1 = 10 * 1 * 2 * 2 = 40      
// Product of elements except 10 = 1  * 1 * 2 * 2 = 4      
// Product of elements except 2 = 1 * 10 * 1 * 2 = 20
// Product of elements except 2 = 1 * 10 * 1 * 2 = 20       

// Test case 2:
// Product of elements except 2 = 12 * 1 * 1 * 20 * 1 = 240
// Product of elements except 12 = 2 * 1 * 1 * 20 * 1 = 40 
// Product of elements except 1 = 2 * 12 * 1 * 20 * 1 = 480   
// Product of elements except 1 = 2 * 12 * 1 * 20 * 1 = 480
// Product of elements except 20 = 2 * 12 * 1 * 1 * 1 = 24  
// Product of elements except 1 = 2 * 12 * 1 * 1* 20 = 480

  
const int MOD = 1000000007;

std::vector<int> productPuzzle(std::vector<int>& arr, int n) {
    std::vector<int> prefixProduct(n, 1); // Initialize prefixProduct array with 1
    std::vector<int> suffixProduct(n, 1); // Initialize suffixProduct array with 1

    // Calculate prefixProduct array
    for (int i = 1; i < n; i++) {
        prefixProduct[i] = (1LL * prefixProduct[i - 1] * arr[i - 1]) % MOD;
    }

    // Calculate suffixProduct array
    for (int i = n - 2; i >= 0; i--) {
        suffixProduct[i] = (1LL * suffixProduct[i + 1] * arr[i + 1]) % MOD;
    }

    std::vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = (1LL * prefixProduct[i] * suffixProduct[i]) % MOD;
    }

    return result;
}
