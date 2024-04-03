Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        if (idx == word.length())
            return true;
        
        int m = board.size();
        int n = board[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[idx])
            return false;
        
        char temp = board[row][col];
        board[row][col] = '#'; // Mark as visited
        
        bool found = dfs(board, word, idx + 1, row + 1, col) ||
                     dfs(board, word, idx + 1, row - 1, col) ||
                     dfs(board, word, idx + 1, row, col + 1) ||
                     dfs(board, word, idx + 1, row, col - 1);
        
        board[row][col] = temp; // Revert back
        
        return found;
    }
Follow up: Could you use search pruning to make your solution faster with a larger board?
