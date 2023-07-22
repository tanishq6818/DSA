

// Problem Statement

// Ninja's friend challenged him with an interesting problem to test his intelligence. His friend gives him the number 'N', Ninja's task is to find the smallest number 'X' such that the product of the digits of 'X' is equal to 'N'Can you help Ninja to solve

// this problem? You are given a number "N", you have to find the minimum number 'X' such that

// product of the digits of 'X' is equal to 'N.If no such number is found, print -1.

// For Example

// If the given number is 36, the smallest number will be 49 as the

// product of digits is 36 (=49).

// the

// Detailed explanation (Input/output format, Notes, Images)

// Constraints:

// 1 <= T <= 10

// 1 <= N <= 10^6.

// Time limit: 1 sec 

def digitProduct(n: int) -> int:
    # If 'n' is 0, then the smallest 'X' is 10 (special case)
    if n == 0:
        return 10

    # If 'n' is a single-digit number, then it is the smallest 'X'
    if n < 10:
        return n

    # Factorize 'n' to get the smallest digits that form 'X'
    digits = []
    for digit in range(9, 1, -1):
        while n % digit == 0:
            digits.append(digit)
            n //= digit

    # If 'n' is not a single-digit number, then there is no 'X' that satisfies the condition
    if n > 1:
        return -1

    # Form the smallest number 'X' from the factors
    x = int("".join(map(str, sorted(digits))))

    return x
