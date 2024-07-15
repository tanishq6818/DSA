Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

Examples:

Input: s = 9, d = 2
Output: 18 
Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
Input: s = 20, d = 3 
Output: 299 
Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
Expected Time Complexity: O(d)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ s ≤ 100
1 ≤ d ≤ 6

  string smallestNumber(int s, int d) {
        if (d * 9 < s)
            return "-1";

        int n = pow(10, d - 1);
        int sum = s - 1;
        string temp = to_string(n);

        int i = d - 1;
        while (i >= 0 && sum > 0) {
            if (sum > 9) {
                temp[i] = '9';
                sum = sum - 9;
            } else {
                int val = temp[i] - '0';
                val = val + sum;
                temp[i] = '0' + val;
                sum = 0;
            }
            i--;
        }
        return temp;
    }
