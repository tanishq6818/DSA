Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

 

Example 1:

Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
Example 2:

Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.
Example 3:

Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
 

Constraints:

1 <= words.length <= 14
1 <= words[i].length <= 15
1 <= letters.length <= 100
letters[i].length == 1
score.length == 26
0 <= score[i] <= 10
words[i], letters[i] contains only lower case English letters.

  class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int W = words.size();
        maxScore = 0;
        freq = vector<int>(26, 0);
        vector<int> subsetLetters = vector<int>(26, 0);
        // Count how many times each letter occurs
        for (char c : letters) {
            freq[c - 'a']++;
        }
        check(W - 1, words, score, subsetLetters, 0);
        return maxScore;
    }

private:
    int maxScore;
    vector<int> freq;

    // Check if adding this word exceeds the frequency of any letter
    bool isValidWord(vector<int>& subsetLetters) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }
        return true;
    }

    void check(int w, vector<string>& words, vector<int>& score, vector<int>& subsetLetters, int totalScore) {
        if (w == -1) {
            // If all words have been iterated, check the score of this subset
            maxScore = max(maxScore, totalScore);
            return;
        }
        // Not adding words[w] to the current subset
        check(w - 1, words, score, subsetLetters, totalScore);
        // Adding words[w] to the current subset
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]++;
            totalScore += score[c];
        }

        if (isValidWord(subsetLetters)) {
            // Consider the next word if this subset is still valid
            check(w - 1, words, score, subsetLetters, totalScore);
        }
        // Rollback effects of this word
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]--;
            totalScore -= score[c];
        }
    }
};
