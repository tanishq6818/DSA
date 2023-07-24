// Sample Input 1:
// 2
// Coding
// Codnig
// Ninjas
// Niaxns
// Sample Output 1:
// YES
// NO
// Explanation For Input 1:
// For test case 1: By swapping ‘i’ and ‘n’ in the second string, it becomes equal to the first string.

// For test case 2: There is no way we can make both the strings equals by swapping one pair of characters.
// Sample Input 2:
// 3
// Hello
// Hello
// Play
// Playes
// Seek
// Seke
// Sample Output 2:
// NO
// NO
// YES




bool checkMeta(string &str1, string &str2) {
    // Check if the lengths of the two strings are different.
    if (str1.length() != str2.length()) {
        return false;
    }

    int firstMismatch = -1;
    int secondMismatch = -1;
    int mismatchCount = 0;

    // Iterate through the strings to find the mismatches.
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            mismatchCount++;

            if (mismatchCount == 1) {
                firstMismatch = i;
            } else if (mismatchCount == 2) {
                secondMismatch = i;
            } else {
                // More than 2 mismatches, can't be made equal by swapping one pair.
                return false;
            }
        }
    }

    // If there are exactly two mismatches and they can be swapped to make the strings equal.
    if (mismatchCount == 2 && str1[firstMismatch] == str2[secondMismatch] && str1[secondMismatch] == str2[firstMismatch]) {
        return true;
    }

    return false;
}
