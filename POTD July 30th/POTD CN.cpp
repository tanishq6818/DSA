// Find the name of the candidate which has max number of votes in an array Sample Input 1 :
// 2
// 4
// John
// Tim
// Marry
// John
// 2
// Rahul
// Ankur
// Sample Output 1 :
// John
// Ankur
// Explanation For Sample Intput 1 :
// For the first test case, “John” has received the maximum number of votes (2 votes).

// For the second test case, both “Rahul” and “Ankur” has received one vote each since “Ankur” is lexicographically smaller than “Rahul”, print “Ankur”.
// Sample Input 2 :
// 2
// 1
// Arya
// 2
// Atul
// Atul    
// Sample Output 2 :
// Arya
// Atul
// Explanation For Sample Intput 2 :
// For the first test case, “Arya” is the only candidate in the election who has received the maximum number of votes.  

// For the second test case, “Atul” has received all the votes.
string getWinner(vector < string > & votes) {
    // Write your code here.
    unordered_map<string, int> voteCount;

    // Count the votes for each candidate
    for (const string& candidate : votes) {
        voteCount[candidate]++;
    }

    int maxVotes = 0;
    string winner;

    // Find the candidate with the maximum number of votes
    for (const auto& pair : voteCount) {
        if (pair.second > maxVotes) {
            maxVotes = pair.second;
            winner = pair.first;
        } else if (pair.second == maxVotes && pair.first < winner) {
            // If there are multiple candidates with the same maximum votes,
            // choose the lexicographically smaller one
            winner = pair.first;
        }
    }

    return winner;
}
