// GfG Weekly + You = Perfect Sunday Evenings!
// Register for free now

// banner
// Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

// Example 1:

// Input : arr[ ] = {7, 3, 5}
// Output : 12
// Explanation:
// All possible pairs and there Xor
// Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)
//  + ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
// Example 2:

// Input : arr[ ] = {5, 9, 7, 6} 
// Output :  47
// Explanation:
// All possible pairs and there Xor
// Value: (5 ^ 9 = 12) + (5 ^ 7 = 2)
//  + (5 ^ 6 = 3) + (9 ^ 7 = 14)
//  + (9 ^ 6 = 15) + (7 ^ 6 = 1)
//  = 12 + 2 + 3 + 14 + 15 + 1 = 47
// Your Task:
// You do not have to take input or print output. You only need to complete the function sumXOR() that takes an array (arr), sizeOfArray (n), and return the sum of xor of all pairs of numbers in the array.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints
// 2 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 105


long long int sumXOR(int arr[], int n) {
    long long int result = 0;
    
    for (int i = 0; i < 32; i++) {
        // Count the number of elements with the ith bit set
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << i)) {
                count++;
            }
        }
        
        // Count the number of elements with the ith bit unset
        int unsetCount = n - count;
        
        // Add the contribution of this bit to the result
        result += (1LL << i) * count * unsetCount;
    }
    
    return result;
}
