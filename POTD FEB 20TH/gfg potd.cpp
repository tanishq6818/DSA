// Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into a space-separated sequence of dictionary words. Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

// Note: From the dictionary dictionary each word can be taken any number of times and in any order.

// Example 1:

// Input:
// n = 6
// s = "ilike"
// dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output:
// 1
// Explanation:
// The string can be segmented as "i like".
// Example 2:

// Input:
// n = 6
// s = "ilikesamsung"
// dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output:
// 1
// Explanation:
// The string can be segmented as 
// "i like samsung" or "i like sam sung".
// Your Task:
// Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

// Expected Time Complexity: O(len(s)2)
// Expected Space Complexity: O(len(s))

// Constraints:
// 1 ≤ n ≤ 12
// 1 ≤ len(s) ≤ 1100


class Solution
{
public:
    //Function to check if the given string can be formed by
    //concatenating words from the dictionary.
    int wordBreak(int n, string s, vector<string> &dictionary) {
        int i, j, k;

        //creating a set to store the words from the dictionary
        set<string> mp;
        for (i = 0; i < n; i++) {
            mp.insert(dictionary[i]);
        }
        int len = (int)s.size();
        //creating a dynamic programming array, initialized as false
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        //iterating through each character of the string
        for (int i = 1; i <= len; i++) {
            //iterating through the substrings of the string
            for (int j = i - 1; j >= 0; j--) {
                //checking if the substring is present in the dictionary
                if (dp[j] && mp.find(s.substr(j, i - j)) != mp.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        //returning the result
        return dp[len];
    }
};
