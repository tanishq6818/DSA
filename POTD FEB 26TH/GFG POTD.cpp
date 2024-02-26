Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

Example 1:

Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicographically sorted order.
Example 2:

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicographically sorted order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints: 
1 <= n <= 16
s will constitute of lower case english alphabets

void generateSubsequences(string s, int index, string current, vector<string>& result) {
    if (index == s.length()) {
        if (!current.empty()) {
            result.push_back(current);
        }
        return;
    }

    // Exclude the current character
    generateSubsequences(s, index + 1, current, result);

    // Include the current character
    generateSubsequences(s, index + 1, current + s[index], result);
}

vector<string> AllPossibleStrings(string s) {
    vector<string> result;
    generateSubsequences(s, 0, "", result);

    // Sort the result lexicographically
    sort(result.begin(), result.end());

    return result;
}
