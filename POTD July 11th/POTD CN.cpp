// Problem Statement

// You are given a binary string 'STR, containing only zeroes and ones. This string does not contain any leading zero. Your task is to determine if this string contains at most one contiguous segment of

// ones,

// Detailed explanation (Input/output format. Notes, Images)

// Constraints:

// 1 <= T <= 10

// 1 <= |STRI < 10^6

// Where T denotes the number of test cases and ISTRI represents length of the string 'STR

// the

// Time Limit: 1sec

// Sample Input 1:

// 1

// 11100

// Y

// Sample Output 1:

// Yes
bool oneSegment(string str) {
	// Write your code here.
	int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1' && (i == 0 || str[i - 1] == '0')) {
            cnt++;
        }
    }
    return cnt <= 1;

}
