// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

// Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once. 

// Example 1:

// Input: 
// grid = {{a,b,c},{d,r,f},{g,h,i}},
// word = "abc"
// Output: 
// {{0,0}}
// Explanation: 
// From (0,0) we can find "abc" in horizontally right direction.
// Example 2:

// Input: 
// grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
// word = "abe"
// Output: 
// {{0,0},{0,2},{1,0}}
// Explanation: 
// From (0,0) we can find "abe" in right-down diagonal. 
// From (0,2) we can find "abe" in left-down diagonal. 
// From (1,0) we can find "abe" in horizontally right direction.
// Your Task:
// You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

// Expected Time Complexity: O(n*m*k) where k is constant
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= n <= m <= 50
// 1 <= |word| <= 15


bool isSafe(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool searchInDirection(vector<vector<char>>& grid, int x, int y, string& word, int dx, int dy) {
    int n = grid.size();
    int m = grid[0].size();
    int len = word.size();

    for (int i = 0; i < len; i++) {
        if (!isSafe(x, y, n, m) || grid[x][y] != word[i]) {
            return false;
        }
        x += dx;
        y += dy;
    }
    return true;
}

vector<vector<int>> searchWord(vector<vector<char>>& grid, string word) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> result;
    set<pair<int, int>> coordinates; // To keep track of unique coordinates

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 8; k++) {
                int newX = i + dx[k] * (word.size() - 1);
                int newY = j + dy[k] * (word.size() - 1);

                if (isSafe(newX, newY, n, m) && searchInDirection(grid, i, j, word, dx[k], dy[k])) {
                    coordinates.insert({i, j});
                }
            }
        }
    }

    for (const auto& coord : coordinates) {
        result.push_back({coord.first, coord.second});
    }

    return result;
}
