// You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

// Return true if a and b are alike. Otherwise, return false.

 

// Example 1:

// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
// Example 2:

// Input: s = "textbook"
// Output: false
// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
// Notice that the vowel o is counted twice.
 

// Constraints:

// 2 <= s.length <= 1000
// s.length is even.
// s consists of uppercase and lowercase letters.

bool halvesAreAlike(std::string s) {
        int n = s.length();
        int mid = n / 2;
        
        // Function to count vowels in a string
        auto countVowels = [](const std::string& str) {
            std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int count = 0;
            for (char ch : str) {
                if (vowels.count(ch) > 0) {
                    count++;
                }
            }
            return count;
        };
        
        // Count vowels in the first and second halves
        int countA = countVowels(s.substr(0, mid));
        int countB = countVowels(s.substr(mid));
        
        // Check if counts are equal
        return countA == countB;
    }
