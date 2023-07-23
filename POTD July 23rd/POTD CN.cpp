// Problem Statement

// Given an integer 'N', you need to make the maximum possible number of moves where each move consists of choosing a positive integer 'X'>1. such that 'N' is divisible by 'X' and replacing 'N' with 'N/X". When 'N' becomes equal to 1 and there are no more possible valid moves. You need to stop and your score is equal to the number of moves made. Given 'N' is of the form a!/b! [i.e. factorial of 'a' divided by factorial of 'b') for some positive integer 'a' and 'b' (ab).

// You need to find and return the maximum possible score you can achieve.

// Detailed explanation (Input/output format, Notes, Images)

// Constraints:

// 1 <T< 10

// 1 < a <- 10^5

// 1 <- b <= 10^5

// Time Limit: 1 sec  Sample Input 1 :
// 2
// 3 1
// 4 4
// Sample Output 1 :
// 2
// 0
// Explanation Of Sample Input 1 :
// For the first test case, we have, a = 3 , b = 1 
// Since N = ( a! / b! )  , N = ( 3! / 1! ) = 6.

// One of the possible ways can be to choose X = 3.
// Then N = ( N / X ) = 6 / 3 = 2.
// Then we choose X = 2 and N becomes 1.
// So, the maximum possible number of rounds = 2.    

// For the second test case, we have, a = 4, b = 4
// Since N = ( a! / b! )  , N = ( 4! / 4! ) = 1.
// We cannot make any move, so there are 0 rounds possible. 
// Sample Input 2 :
// 2
// 6 4
// 5 1
// Sample Output 2 :
// 3
// 5

int Rounds(int a,int b){
  // Write your code here
  // Calculate the value of N = a! / b!
    int n = 1;
    for (int i = b + 1; i <= a; i++) {
        n *= i;
    }

    // Count the number of moves
    int moves = 0;
    while (n > 1) {
        bool found_divisor = false;
        // Try to find a divisor X
        for (int x = 2; x <= n; x++) {
            if (n % x == 0) {
                n /= x;
                moves++;
                found_divisor = true;
                break;
            }
        }

        // If no divisor is found, break the loop
        if (!found_divisor) {
            break;
        }
    }

    return moves;
}
