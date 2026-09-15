// #include<iostream>
// using namespace std;
// void  func(int i ,int n){
//   if (i>n) return ;
//   cout<<" "<<i;
//   func(i+1,n);
// }
// int main(){

// func(1,10);
//   return 0;
// }

// #include <iostream>
// using namespace std;
// void func(int n)
// {
//   if (n == 0)
//   {
//     cout << "\n";
//     return;
//   }
//   cout << " " << n;
//   func(n - 1);
// }
// int main()
// {

//   func(100);
//   return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     // Helper function to generate permutations recursively
//     void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
//         // Base Case: If index reaches the end, a full permutation is formed
//         if (idx == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }

//         // Loop to explore all choices for the current position 'idx'
//         for (int i = idx; i < nums.size(); i++) {
//             swap(nums[idx], nums[i]); // Choose: Put ith element at idx position
//             getPerms(nums, idx + 1, ans); // Explore: Recurse for the next index
//             swap(nums[idx], nums[i]); // Unchoose: Backtrack to restore original state
//         }
//     }

//     // Main function called by the user
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         getPerms(nums, 0, ans); // Start recursion from index 0
//         return ans;
//     }
// };

// int main() {
//     Solution solver;
//     vector<int> nums = {1, 2, 3}; // Sample input

//     vector<vector<int>> result = solver.permute(nums);

//     // Print the permutations
//     cout << "[" << endl;
//     for (const auto& perm : result) {
//         cout << "  [";
//         for (size_t i = 0; i < perm.size(); ++i) {
//             cout << perm[i];
//             if (i < perm.size() - 1) cout << ", ";
//         }
//         cout << "]" << endl;
//     }
//     cout << "]" << endl;

//     return 0;
// }

// subset
// #include <iostream>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//     // Helper function to generate subsets recursively
//     void getSubsets(vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& ans) {
//         // Base Case: If we have processed all elements, add the current subset to answer
//         if (idx == nums.size()) {
//             ans.push_back(current);
//             return;
//         }

//         // Choice 1: Include the current element nums[idx]
//         current.push_back(nums[idx]);
//         getSubsets(nums, idx + 1, current, ans);

//         // Unchoose: Backtrack to explore the other choice
//         current.pop_back();

//         // Choice 2: Exclude the current element nums[idx]
//         getSubsets(nums, idx + 1, current, ans);
//     }

//     // Main function called by the user
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> current;
//         getSubsets(nums, 0, current, ans); // Start recursion from index 0
//         return ans;
//     }
// };

// int main() {
//     Solution solver;
//     vector<int> nums = {1, 2, 3}; // Sample input

//     vector<vector<int>> result = solver.subsets(nums);

//     // Print the subsets
//     cout << "[" << endl;
//     for (const auto& sub : result) {
//         cout << "  [";
//         for (size_t i = 0; i < sub.size(); ++i) {
//             cout << sub[i];
//             if (i < sub.size() - 1) cout << ", ";
//         }
//         cout << "]" << endl;
//     }
//     cout << "]" << endl;

//     return 0;
// }

// n queens
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// class Solution {
// public:
//     // Helper function to check if placing a queen at (row, col) is safe
//     bool isSafe(int row, int col, int n, const vector<string>& board) {
//         // 1. Check vertical column up
//         for (int i = 0; i < row; ++i) {
//             if (board[i][col] == 'Q') return false;
//         }

//         // 2. Check upper-left diagonal
//         for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
//             if (board[i][j] == 'Q') return false;
//         }

//         // 3. Check upper-right diagonal
//         for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
//             if (board[i][j] == 'Q') return false;
//         }

//         return true;
//     }

//     // Helper function to solve N-Queens recursively row by row
//     void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
//         // Base Case: If all rows are filled, a valid configuration is found
//         if (row == n) {
//             ans.push_back(board);
//             return;
//         }

//         // Try placing a queen in each column of the current row
//         for (int col = 0; col < n; ++col) {
//             if (isSafe(row, col, n, board)) {
//                 board[row][col] = 'Q';       // Choose: Place the queen
//                 solve(row + 1, n, board, ans); // Explore: Move to the next row
//                 board[row][col] = '.';       // Unchoose: Backtrack
//             }
//         }
//     }

//     // Main function called by the user
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         // Initialize an empty board with '.'
//         vector<string> board(n, string(n, '.'));
//         solve(0, n, board, ans); // Start from row 0
//         return ans;
//     }
// };

// int main() {
//     Solution solver;
//     int n = 4; // Change this value to solve for different board sizes (e.g., 8)

//     vector<vector<string>> result = solver.solveNQueens(n);

//     cout << "Found " << result.size() << " solutions for " << n << "-Queens:" << endl << endl;

//     // Print each solution board
//     for (size_t k = 0; k < result.size(); ++k) {
//         cout << "Solution " << k + 1 << ":" << endl;
//         for (const string& row : result[k]) {
//             for (char cell : row) {
//                 cout << cell << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// // SUCUKO SOLVER
#include <iostream>
#include <vector>

using namespace std;

// 1. Helper function to check if placing 'dig' at board[row][col] is valid
bool isSafe(vector<vector<char>> &board, int row, int col, char dig) {
    int gridRow = (row / 3) * 3;
    int gridCol = (col / 3) * 3;

    for (int i = 0; i < 9; i++) {
        // Check the row
        if (board[row][i] == dig) return false;
        
        // Check the column
        if (board[i][col] == dig) return false;
        
        // Check all 9 cells of the 3x3 subgrid using i/3 and i%3 offsets
        if (board[gridRow + (i / 3)][gridCol + (i % 3)] == dig) return false; 
    }
    return true;
}

// 2. Core recursive backtracking function
bool solveSudokuHelper(vector<vector<char>> &board, int row, int col)
{
    // Base case: If we reach row 9, the entire board is successfully filled
    if (row == 9)
    {
        return true;
    }

    // Calculate the coordinates for the next cell
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If current cell already contains a number, skip it and move to the next
    if (board[row][col] != '.')
    {
        return solveSudokuHelper(board, nextRow, nextCol);
    }

    // Try placing digits from '1' to '9'
    for (int dig = 1; dig <= 9; dig++)
    {
        char digChar = '0' + dig; // Convert integer digit to char

        if (isSafe(board, row, col, digChar))
        {
            board[row][col] = digChar; // Place the digit

            // Recursively try to solve the rest of the board
            if (solveSudokuHelper(board, nextRow, nextCol))
            {
                return true;
            }

            // Backtracking step: undo choice if it doesn't lead to a solution
            board[row][col] = '.';
        }
    }

    return false; // Trigger backtracking to previous cells
}

// 3. Wrapper function to start the solver from (0,0)
void solveSudoku(vector<vector<char>> &board)
{
    solveSudokuHelper(board, 0, 0);
}

int main()
{
    // 4. Create a sample 9x9 Sudoku grid ('.' represents empty slots)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "--- Original Sudoku Board ---" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // 5. Run the procedural solver function
    solveSudoku(board);

    cout << "\n--- Solved Sudoku Board ---" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// rat in maze
// // #include <iostream>
// // #include <vector>
// // #include <string>

// // using namespace std;

// // // 1. Helper function to check if moving to maze[row][col] is safe and valid
// // bool isSafe(int row, int col, int n, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
// //     // Check boundaries, if it's a wall (0), or if it has already been visited
// //     if (row < 0 || row >= n || col < 0 || col >= n || maze[row][col] == 0 || visited[row][col]) {
// //         return false;
// //     }
// //     return true;
// // }

// // 2. Core recursive backtracking function to find all paths
// void findPathsHelper(int row, int col, int n, vector<vector<int>>& maze, 
//                          vector<vector<bool>>& visited, string currentPath, vector<string>& ans) {
//     // Base Case: If the rat reaches the bottom-right corner, store the path
//     if (row == n - 1 && col == n - 1) {
//         ans.push_back(currentPath);
//         return;
//     }

//     // Mark the current cell as visited before moving forward
//     visited[row][col] = true;

//     // Lexicographical order directions: Down, Left, Right, Up (D, L, R, U)

//     // Move Down
//     if (isSafe(row + 1, col, n, maze, visited)) {
//         findPathsHelper(row + 1, col, n, maze, visited, currentPath + 'D', ans);
//     }

//     // Move Left
//     if (isSafe(row, col - 1, n, maze, visited)) {
//         findPathsHelper(row, col - 1, n, maze, visited, currentPath + 'L', ans);
//     }

//     // Move Right
//     if (isSafe(row, col + 1, n, maze, visited)) {
//         findPathsHelper(row, col + 1, n, maze, visited, currentPath + 'R', ans);
//     }

//     // Move Up
//     if (isSafe(row - 1, col, n, maze, visited)) {
//         findPathsHelper(row - 1, col, n, maze, visited, currentPath + 'U', ans);
//     }

//     // Backtracking step: Unmark the current cell for other potential path options
//     visited[row][col] = false;
// }

// // 3. Wrapper function called by the user
// vector<string> findPaths(vector<vector<int>>& maze, int n) {
//     vector<string> ans;
//     // Base edge case: If start or destination is blocked, no path exists
//     if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
//         return ans;
//     }

//     // Initialize an empty tracking grid for visited states
//     vector<vector<bool>> visited(n, vector<bool>(n, false));
    
//     findPathsHelper(0, 0, n, maze, visited, "", ans);
//     return ans;
// }

// // 4. Main function to execute and test the program
// int main() {
//     // 1 represents an open path, 0 represents a wall/block
//     int n = 4;
//     vector<vector<int>> maze = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}
//     };

//     cout << "--- Maze Grid (1=Path, 0=Wall) ---" << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << maze[i][j] << " ";
//         }
//         cout << endl;
//     }

//     // Solve and gather all viable routing strings
//     vector<string> result = findPaths(maze, n);

//     cout << "\n--- Solutions Found: " << result.size() << " ---" << endl;
//     if (result.empty()) {
//         cout << "No paths available to reach the destination!" << endl;
//     } else {
//         for (const string& path : result) {
//             cout << "Path: " << path << endl;
//         }
//     }

//     return 0;
// }
