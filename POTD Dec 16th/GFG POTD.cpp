// Given a length n, count the number of strings of length n that can be made using a, b and c with at-most one b and two c allowed.

// Example 1:

// Input: n = 1
// Output: 3
// Explanation: Possible strings are: "a",
// "b" and "c"
// Example 2:

// Input: n = 3
// Output: 19
// Explanation: Number of strings with 3 
// occurrances of a: 1
// 2-a and 1-b: 3
// 2-a and 1-c: 3
// 1-a, 1-b and 1-c: 6
// 1-a and 2-c: 3
// 1-b and 2-c: 3
// So, total number of strings of length 3
// is 1 + 3 + 3 + 6 + 3 + 3 = 19
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function countStr() which takes the n as inputs and returns the total number of valid strings.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 105

long long int countStr(long long int n) {
    // Total strings with a, b, and c
    long long totalStrings = pow(3, n);

    // Number of strings with more than one 'b'
    long long stringsWithMoreThanOneB = pow(2, n);

    // Number of strings with more than two 'c'
    long long stringsWithMoreThanTwoC = pow(2, n) + n * pow(2, n - 1);

    // Subtract the invalid strings from the total to get the valid strings
    long long validStrings = totalStrings - (stringsWithMoreThanOneB + stringsWithMoreThanTwoC);

    return validStrings;
}
