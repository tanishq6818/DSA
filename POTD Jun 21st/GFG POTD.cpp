// You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

// Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

// Examples

// Input: str = "5/6, 11/45"
// Output: 5/6
// Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
// Input: str = "8/1, 8/1"
// Output: equal
// Explanation: We can see that both the fractions are same, so we'll return a string "equal".
// Input: str = "10/17, 9/10"
// Output: 9/10
// Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".
// Expected Time Complexity: O(len|str|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0<=a,c<=103
// 1<=b,d<=103

string compareFrac(string str) {

        // Initializing numerator and denominator variables.
        int a, b, c, d;
        a = b = c = d = 0;

        // Regular expression to match and extract numerical values from string.
        regex re("([0-9]+)\\/([0-9]+), ([0-9]+)\\/([0-9]+)",
                 regex_constants::ECMAScript);
        smatch sm;

        // Matching and extracting values using regex.
        if (regex_search(str, sm, re)) {

            a = stoi(sm[1]);
            b = stoi(sm[2]);
            c = stoi(sm[3]);
            d = stoi(sm[4]);
        }

        // Variable to store the comparison result.
        string ans = "";

        // Comparing fractions and updating the result variable accordingly.
        if (a * d > b * c) {
            ans += to_string(a);
            ans += "/";
            ans += to_string(b);
        } else if (b * c > a * d) {
            ans += to_string(c);
            ans += "/";
            ans += to_string(d);
        } else {
            ans = "equal";
        }

        // Returning the result.
        return ans;
    }
