Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
string removeDuplicateLetters(string s) {
    vector<int> lastOccurrence(26, -1);
    vector<bool> inStack(26, false);
    stack<char> charStack;

    // First, record the last occurrence index of each character in the string.
    for (int i = 0; i < s.length(); i++) {
        lastOccurrence[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.length(); i++) {
        char currentChar = s[i];

        // Skip characters that are already in the stack.
        if (inStack[currentChar - 'a']) {
            continue;
        }

        // Pop characters from the stack if they are greater than the current character
        // and still have remaining occurrences later in the string.
        while (!charStack.empty() &&
               currentChar < charStack.top() &&
               lastOccurrence[charStack.top() - 'a'] > i) {
            inStack[charStack.top() - 'a'] = false;
            charStack.pop();
        }

        // Push the current character onto the stack.
        charStack.push(currentChar);
        inStack[currentChar - 'a'] = true;
    }

    // Build the result string from the stack.
    string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }

    return result;
}
