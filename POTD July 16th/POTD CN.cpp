// Sample Input 1:
// 4
// 123.111.12.k
// 122.0.330.0
// 1.1.1.250
// 1.0.0.0.1
// Sample Output 1:
// False
// False
// True
// False
// Explanation Of Sample Input 1:
// Test Case 1:
// Given text ‘IPAddress = 123.111.12.k’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed but it not satisfying the second condition that d must in a range of ‘0’ to ‘255’ but the value of ‘d’ is ‘k’.
// Hence return ‘False’.

// Test Case 2:
// Given text ‘IPAddress = 122.0.330.0’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed but it not satisfying the second condition that c must in a range of ‘0’ to ‘255’ but the value of ‘c’ is ‘330’ and it is out of range.
// Hence return ‘False’.

// Test Case 3:
// Given text ‘IPAddress = 1.1.1.250’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed as well as it satisfying the second condition that a,b,c, and d must in range of ‘0’ to ‘250’.
// Hence return ‘True’.

// Test Case 4:
// Given text ‘IPAddress = 1.0.0.0.1’, it is not satisfying the first condition for valid ‘IPv4’, that text ‘IPAddress’ must be in form of ‘a.b.c.d’ but given text is a form of ‘a.b.c.d.e’
// Hence return ‘False’.
// Sample Input 2:
// 2
// 1.90.21.1
// 1.1
// Sample Output 2:
// True
// False

bool isValidIPv4(string& ipAddress) {
    // Split the IP address into tokens using the dot as a delimiter
    vector<string> tokens;
    stringstream ss(ipAddress);
    string token;
    while (getline(ss, token, '.')) {
        tokens.push_back(token);
    }

    // Check if the number of tokens is exactly 4
    if (tokens.size() != 4) {
        return false;
    }

    // Check if each token is a valid integer between 0 and 255
    for (const string& token : tokens) {
        // Check if the token is a valid integer
        if (token.empty() || token.size() > 3) {
            return false;
        }

        for (char c : token) {
            if (!isdigit(c)) {
                return false;
            }
        }

        int num = stoi(token);
        // Check if the integer is within the range 0 to 255
        if (num < 0 || num > 255) {
            return false;
        }
    }

    return true;
}
