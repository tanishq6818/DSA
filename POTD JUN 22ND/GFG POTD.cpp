Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

Note: Numbers and words are separated by spaces only.

Examples :

Input: sentence="This is alpha 5057 and 97"
Output: 5057
Explanation: 5057 is the only number that does
not have a 9.
Input: sentence="Another input 9007"
Output: -1
Explanation: Since there is no number that
does not contain a 9,output is -1.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)

Constraints:
1<=n<=106
1<=answer<=1018

n is the length of a given sentence.

  long long ExtractNumber(string sentence) {
        regex regex("\\d+");
        smatch match;
        string s = sentence;
        vector<string> numbers;

        while (regex_search(s, match, regex)) {
            numbers.push_back(match.str());
            s = match.suffix().str();
        }

        long long ans = -1;
        long long lens = LLONG_MIN;

        for (const auto& num : numbers) {
            if (num.find('9') == string::npos) {
                long long numValue = stoll(num);
                if (lens < numValue) {
                    ans = numValue;
                    lens = numValue;
                }
            }
        }

        return ans;
    }
