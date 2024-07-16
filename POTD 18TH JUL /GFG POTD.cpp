Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that remains after the character ch has appeared count number of times.
Note:  Assume upper case and lower case alphabets are different. “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.

Examples:

Input: s = "Thisisdemostring", ch = 'i', count = 3
Output: ng
Explanation: The remaining substring of s after the 3rd
occurrence of 'i' is "ng", hence the output is ng.
Input: s = "Thisisdemostri", ch = 'i', count = 3
Output: ""
Explanation: The 3rd occurence of 'i' is at the last index. In this case the remaining substring is empty, hence we return empty string.
Input: s = "abcd", ch = 'x', count = 2
Output: ""
Explanation: The character x is not present in the string, hence we return empty string.
Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1)

Constraints:
1<= s.length()<=105
1<=count<=s.length()
s[i] is both upper case and lower case

string printString(string s, char ch, int count) {
    int charCount = 0;
    size_t index = 0;
    
    // Traverse through the string to find the count-th occurrence of ch
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == ch) {
            charCount++;
            if (charCount == count) {
                index = i + 1; // Index of character immediately after the count-th occurrence
                break;
            }
        }
    }
    
    // If we found the count-th occurrence of ch
    if (charCount == count) {
        return s.substr(index);
    } else {
        return ""; // If ch does not occur count times in the string
    }
}
