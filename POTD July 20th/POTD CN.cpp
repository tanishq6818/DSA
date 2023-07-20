// Ayush is given a number 'X'. He has been told that he has to find the first 'X'  terms of the series 3 * 'N' + 2 which are not the multiples of 4  Sample Input 1:
// 2
// 2
// 5
// Sample Output 1:
// 5 11
// 5 11 14 17 23
// Explanation For Sample Input 1:
// In the first test case, the first number is 5, while the second number cannot be 8 as it is divisible by 4, and so, the next number is directly 11 as it is not divisible by 4.

// In the second test case, the first two numbers are 5 and 11. While following three numbers are 14, 17 and 23 for ‘N’ = 4, 5 and 7 respectively. 20 is divisible by 4, and thus, 20 cannot be included in the list.
// Sample Input 2:
// 2
// 7
// 8
// Sample Output 2:
// 5 11 14 17 23 26 29
// 5 11 14 17 23 26 29 35
// Explanation For Sample Input 2:
// In the first test case, the first five numbers are 5, 11, 14, 17 and 23. While the following two numbers are 26 and 29 for N = 8 and 9 respectively.

// In the second test case, the seven numbers are explained in the above test case and for N = 10, we get the number 32, which is divisible by 4 and thus, we reject it. For N = 11, the number is 35 and is not divisible by 4.


bool isNotMultipleOfFour(int num) {
    return num % 4 != 0;
}

vector<int> termsOfAP(int x) {
    vector<int> sequence;
    int num = 5; // Starting number
    int count = 0;

    while (count < x) {
        if (isNotMultipleOfFour(num)) {
            sequence.push_back(num);
            count++;
        }
        num += 3;
    }

    return sequence;
}
