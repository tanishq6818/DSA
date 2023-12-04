// Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string when it is broken down into more than one substring and the rightmost substring can be written as a sum of two substrings before it and the same is recursively true for substrings before it.

// Example 1:

// Input:
// S = "12243660"
// Output:
// 1
// Explanation:
// "12243660" can be broken down as {"12", "24", "36", "60"}.
// We can get 60 from 24 and 36 as 24 + 36 = 60. Similarly 36 can be written as 12 + 24.
// Example 2:

// Input:
// 1111112223
// Output:
// 1
// Explanation:
// "1111112223" can be broken down as {"1", "111", "112", "223"}.
// We can get 223 from 111 and 1112 as 111 + 112 = 223. Similarly 112 can be written as 1 + 111.
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function isSumString() which takes the string S and returns 1 is S is a sum-string otherwise returns 0.

// Expected Time Complexity: O(|S|3)
// Expected Auxiliary Space: O(|S|)

// Constraints:
// 1 <= |S| <= 500
// String consists of characters from '0' to '9'.

class Solution{   

public:
    // Function to add two strings representing numbers
    string string_sum(string str1, string str2)
    {
        // Swapping the strings if str1 has fewer digits than str2
        if (str1.size() < str2.size())
            swap(str1, str2);

        int m = str1.size();
        int n = str2.size();
        string ans = "";
        int carry = 0;

        // Adding digits from right to left
        for (int i = 0; i < n; i++) 
        {
            // Calculating sum and carry for current digits
            int ds = ((str1[m - 1 - i] - '0') +
                        (str2[n - 1 - i] - '0') +
                        carry) % 10;

            carry = ((str1[m - 1 - i] - '0') +
                        (str2[n - 1 - i] - '0') +
                        carry) / 10;

            ans = char(ds + '0') + ans;
        }

        // Adding remaining digits from str1
        for (int i = n; i < m; i++) 
        {
            int ds = (str1[m - 1 - i] - '0' +
                        carry) % 10;
            carry = (str1[m - 1 - i] - '0' +
                        carry) / 10;
            ans = char(ds + '0') + ans;
        }

        // Adding the final carry if present
        if (carry)
            ans = char(carry + '0') + ans;
        return ans;
    }

    // Function to check if string can be split into a sum string
    bool checkSumStrUtil(string str, int beg,
                        int len1, int len2)
    {
        // Getting the substring corresponding to the first number
        string s1 = str.substr(beg, len1);

        // Getting the substring corresponding to the second number
        string s2 = str.substr(beg + len1, len2);

        // Calculating the sum of the two numbers
        string s3 = string_sum(s1, s2);

        int s3_len = s3.size();

        // If the length of the sum is greater than the remaining substring,
        // then it is not a sum string
        if (s3_len > str.size() - len1 - len2 - beg)
            return false;

        // If the sum matches the next substring, check recursively for the remaining substring
        if (s3 == str.substr(beg + len1 + len2, s3_len)) 
        {
            // If there are no remaining substrings, it is a sum string
            if (beg + len1 + len2 + s3_len == str.size())
                return true;

            // Checking for the remaining substring
            return checkSumStrUtil(str, beg + len1, len2,
                                    s3_len);
        }
        return false;
    }

    // Function to check if a string can be split into a sum string
    bool isSumStr(string str)
    {
        int n = str.size();

        // Checking all possible combinations of splitting the string into two numbers
        for (int i = 1; i < n; i++)
            for (int j = 1; i + j < n; j++)
                if (checkSumStrUtil(str, 0, i, j))
                    return true;

        return false;
    }

    // Function to check if a string is a sum string
    int isSumString(string S)
    {
        return isSumStr(S);
    }
};
