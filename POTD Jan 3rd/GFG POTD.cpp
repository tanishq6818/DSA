Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = 01212
Output:
3
Explanation:
The substring 012 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input: 
S = 12121
Output:
-1
Explanation: 
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.
Your Task:
Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.

Expected Time Complexity: O( length( S ) )
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length( S ) ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}

int smallestSubstring(string S) 
{
    int n = S.length();

    int count[3] = {0}; // To count occurrences of 0, 1, and 2
    int start = 0; // Start of the window
    int minLength = INT_MAX; // To store the length of the smallest substring

    for (int end = 0; end < n; end++) {
        // Update count for the current character
        count[S[end] - '0']++;

        // Try to minimize the window by moving the start pointer
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            // Update the minimum length
            minLength = min(minLength, end - start + 1);

            // Move the start pointer
            count[S[start] - '0']--;
            start++;
        }
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}
