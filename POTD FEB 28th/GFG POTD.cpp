// Given a string representation of a decimal number s, check whether it is divisible by 8.

// Example 1:

// Input:
// s = "16"
// Output:
// 1
// Explanation:
// The given number is divisible by 8,
// so the driver code prints 1 as the output.
// Example 2:

// Input:
// s = "54141111648421214584416464555"
// Output:
// -1
// Explanation:
// Given Number is not divisible by 8, 
// so the driver code prints -1 as the output.
// Your Task:
// You don't need to read input or print anything.Your task is to complete the function DivisibleByEight() which takes a string s as the input and returns 1 if the number is divisible by 8, else it returns -1.

// Expected Time Complexity: O(1).
// Expected Auxillary Space: O(1).

// Constraints:
// 1 <= |s| <= 106

 int DivisibleByEight(string s) {
        int n = s.length();
        
        // If the length of the string is 1, check if it is divisible by 8
        if (n == 1) {
            return (stoi(s) % 8 == 0) ? 1 : -1;
        }
        
        // If the length of the string is 2, check if the number formed by the two digits is divisible by 8
        if (n == 2) {
            return ((s[0] - '0') * 10 + (s[1] - '0')) % 8 == 0 ? 1 : -1;
        }
        
        // Check if the last three digits of the number are divisible by 8
        int lastThreeDigits = (s[n - 3] - '0') * 100 + (s[n - 2] - '0') * 10 + (s[n - 1] - '0');
        if (lastThreeDigits % 8 == 0) {
            return 1;
        }
        
        return -1;
    }
