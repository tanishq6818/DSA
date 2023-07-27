// Sample Input 1:
//  2
//  12
//  5
// Sample Output 1:
// 1 2 3 4 5 6 7 8 9 11
// 1 2 3 4 5
// Explanation:
// For the first test case, all the single-digit numbers are palindromic, and the number 11 is also palindromic. Hence the output is [1, 2, 3, 4, 5, 6, 7, 8, 9, 11].

// For the second test case, N is less than 9. Therefore all the numbers from 1 to N are palindromes. Hence the output is [1, 2, 3, 4, 5].
// Sample Input 2:
//  2
//  15
//  22
// Sample Output 2:
// 1 2 3 4 5 6 7 8 9 11
// 1 2 3 4 5 6 7 8 9 11 22

  
bool isPalindrome(int num) {
    string numStr = to_string(num);
    int left = 0;
    int right = numStr.length() - 1;
    while (left < right) {
        if (numStr[left] != numStr[right])
            return false;
        left++;
        right--;
    }
    return true;
}

vector<int> getPalindromes(int n) {
    vector<int> palindromes;
    for (int i = 1; i <= n; i++) {
        if (isPalindrome(i))
            palindromes.push_back(i);
    }
    return palindromes;
}
