Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 

Note: The number may have leading zeros.

Example 1:

Input:
s = "1234"
Output: 
1670
Explanation: 
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670
Example 2:

Input:
s = "421"
Output: 
491
Explanation: 
Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491
Your Task:
You only need to complete the function sumSubstrings that takes s as an argument and returns the answer modulo 109+7.

Expected Time Complexity: O(|s|).
Expected Auxiliary Space: O(|s|).

Constraints:
1 <= |s| <= 105

  #define MOD 1000000007

long long sumSubstrings(string s){
    long long totalSum = 0; // To store the total sum of all substrings
    long long lastValue = 0; // To store the sum contributed by the last digit processed
    
    for (int i = 0; i < s.length(); ++i) {
        // The contribution of the current digit is its value times its position (i+1)
        // plus 10 times the last value it contributed (because of its place in new numbers formed)
        lastValue = (lastValue * 10 + (s[i] - '0') * (i + 1)) % MOD;
        
        // Add the current value to the total sum
        totalSum = (totalSum + lastValue) % MOD;
    }
    
    return totalSum;
}
