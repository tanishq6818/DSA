// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.
 

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.
// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
vector<string> getWords(int& i, vector<string>& words, int maxWidth) {
    vector<string> currentLine;
    int currLength = 0;

    while (i < words.size() && currLength + words[i].length() <= maxWidth) {
        currentLine.push_back(words[i]);
        currLength += words[i].length() + 1;
        i++;
    }

    return currentLine;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0;

    while (i < words.size()) {
        vector<string> currentLine = getWords(i, words, maxWidth);
        int wordCount = currentLine.size();
        int totalLength = 0;

        for (const string& word : currentLine) {
            totalLength += word.length();
        }

        int spacesToAdd = maxWidth - totalLength;

        if (wordCount == 1 || i == words.size()) {
            string line = currentLine[0];
            for (int j = 1; j < wordCount; j++) {
                line += " " + currentLine[j];
            }
            line += string(maxWidth - line.length(), ' ');
            result.push_back(line);
        } else {
            int spacesBetweenWords = spacesToAdd / (wordCount - 1);
            int extraSpaces = spacesToAdd % (wordCount - 1);

            string line = currentLine[0];
            for (int j = 1; j < wordCount; j++) {
                line += string(spacesBetweenWords + (j <= extraSpaces), ' ') + currentLine[j];
            }
            result.push_back(line);
        }
    }

    return result;
}
