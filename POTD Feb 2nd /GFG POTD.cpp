// Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

// Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and rest are numeric.

// Example 1:

// Input:
// s = "-123"
// Output: 
// -123
// Explanation:
// It is possible to convert -123 into an integer 
// and is so returned in the form of an integer
// Example 2:

// Input:
// s = "21a"
// Output: 
// -1
// Explanation: 
// The output is -1 as, due to the inclusion of 'a',
// the given string cannot be converted to an integer.
// Your Task:
// You do not have to take any input or print anything. Complete the function atoi() which takes a string s as an input parameter and returns an integer value representing the given string. If the conversion is not feasible, the function should return -1.

// |s| = length of string str.
// Expected Time Complexity: O( |s| ), 
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |s| ≤ 10


 bool isNumericChar(char x) {
        return (x >= '0' && x <= '9')? true: false;
    }
    
    // Function to convert string to integer
    int atoi(string s)
    {
        int n = s.size();
        if (s == "")
            return 0;
      
        int res = 0;  
        int sign = 1;  
        int i = 0; 
      
        // Check for negative sign
        if (s[0] == '-')
        {
            sign = -1;
            i++;  
        }
      
        // Convert each character to integer and calculate the result
        for (; i < n; ++i)
        {
            if (isNumericChar(s[i]) == false)
                return -1; 
            res = res * 10 + s[i] - '0';
        }
      
        // Return result with sign
        return sign * res;
    }
