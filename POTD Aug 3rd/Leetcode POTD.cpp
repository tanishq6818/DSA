// // A mapping of digits to letters
// const vector<string> digitToLetters = {
//     "",     // 0
//     "",     // 1
//     "abc",  // 2
//     "def",  // 3
//     "ghi",  // 4
//     "jkl",  // 5
//     "mno",  // 6
//     "pqrs", // 7
//     "tuv",  // 8
//     "wxyz"  // 9
// };

// void backtrack(string& digits, int index, string& current, vector<string>& result) {
//     if (index == digits.length()) {
//         result.push_back(current);
//         return;
//     }

//     int digit = digits[index] - '0';
//     for (char c : digitToLetters[digit]) {
//         current.push_back(c);
//         backtrack(digits, index + 1, current, result);
//         current.pop_back();
//     }
// }

// vector<string> letterCombinations(string digits) {
//     vector<string> result;
//     if (digits.empty()) return result;
//     string current;
//     backtrack(digits, 0, current, result);
//     return result;
// }

// Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
