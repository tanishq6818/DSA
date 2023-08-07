// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.


// Sample Sudoku for you to get the logic for its solution:



// Example 1:

// Input:
// grid[][] = 
// [[3 0 6 5 0 8 4 0 0],
// [5 2 0 0 0 0 0 0 0],
// [0 8 7 0 0 0 0 3 1 ],
// [0 0 3 0 1 0 0 8 0],
// [9 0 0 8 6 3 0 0 5],
// [0 5 0 0 9 0 6 0 0],
// [1 3 0 0 0 0 2 5 0],
// [0 0 0 0 0 0 0 7 4],
// [0 0 5 2 0 6 3 0 0]]
// Output:
// True
// 3 1 6 5 7 8 4 9 2
// 5 2 9 1 3 4 7 6 8
// 4 8 7 6 2 9 5 3 1
// 2 6 3 4 1 5 9 8 7
// 9 7 4 8 6 3 1 2 5
// 8 5 1 7 9 2 6 4 3
// 1 3 8 9 4 7 2 5 6
// 6 9 2 3 5 1 8 7 4
// 7 4 5 2 8 6 3 1 9
// Explanation: 
// There exists a valid Sudoku for the input grid, which is shown in output.
// Example 2:

// Input:
// grid[][] = 
// [[3 6 6 5 0 8 4 0 0],
// [5 2 0 0 0 0 0 0 0],
// [0 8 7 0 0 0 0 3 1 ],
// [0 0 3 0 1 0 0 8 0],
// [9 0 0 8 6 3 0 0 5],
// [0 5 0 0 9 0 6 0 0],
// [1 3 0 0 0 0 2 5 0],
// [0 0 0 0 0 0 0 7 4],
// [0 0 5 2 0 6 3 0 0]]
// Output:
// False
// Explanation: 
// There does not exists a valid Sudoku for the input grid, since there are two 6s in the first row. Which cannot replaced.
// Your Task:
// You need to complete the two functions:

// SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not, on returning false driver will print "No solution exists".

// printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation. Do not give a new line character after printing the grid.

// Expected Time Complexity: O(9N*N).
// Expected Auxiliary Space: O(N*N).

// Constraints:
// 0 ≤ grid[i][j] ≤ 9 

  
const int N = 9;

// Function to check if a digit can be placed at a specific position in the grid
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not present in the current row and column
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    
    // Check if the number is not present in the current 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool SolveSudoku(int grid[N][N]) {
    int row, col;
    
    // Find an empty cell (with value 0)
    if (!findEmptyCell(grid, row, col)) {
        return true; // All cells are filled, puzzle is solved
    }
    
    // Try placing digits from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (SolveSudoku(grid)) {
                return true; // Successfully solved the puzzle
            }
            
            grid[row][col] = 0; // Backtrack and try a different number
        }
    }
    
    return false; // No valid number can be placed in this cell
}

// Function to find an empty cell (with value 0) in the grid
bool findEmptyCell(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true; // Found an empty cell
            }
        }
    }
    return false; // All cells are filled
}

// Function to print the solved Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
    }
}
