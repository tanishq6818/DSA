Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

   string removeKdigits(string num, int k) {
        string result;
        for(char digit : num) {
            // While there's something in the result, the last digit in result is greater than the current digit,
            // and we still have digits to remove
            while(!result.empty() && result.back() > digit && k > 0) {
                result.pop_back(); // Remove the last digit from result
                k--;
            }
            result.push_back(digit); // Add current digit to result
        }
        
        // If we still need to remove more digits
        while(k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int startIndex = 0;
        while(startIndex < result.size() && result[startIndex] == '0') {
            startIndex++;
        }
        result = result.substr(startIndex);

        // If result is empty, return "0", else return result
        return result.empty() ? "0" : result;
    }
