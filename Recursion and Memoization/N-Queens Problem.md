### Problem Statement: N-Queen Problem

**Objective**:
Write a program to solve the N-Queen problem. The goal is to place N queens on an N×N chessboard such that no two queens threaten each other. This means no two queens can be in the same row, column, or diagonal. The program should print one valid solution if it exists.

**Constraints**:
- The input is an integer `N` representing the size of the chessboard (N×N) and the number of queens to be placed.
- Each queen must be placed on a different row, column, and diagonal.

**Input**:
- An integer `N` representing the size of the chessboard.

**Output**:
- Print one valid configuration of the chessboard with queens placed such that no two queens threaten each other.
- If no solution exists, indicate that no solution exists.

**Example**:
```
Input:
N = 4

Output:
Solution to the N-Queen problem:
0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 
```

**Explanation**:
- One possible solution to the 4-Queen problem is shown. The `1`s represent the positions of the queens, and the `0`s represent empty cells.

**Function Signature**:
```cpp
bool isSafe(vector<vector<int>>& board, int row, int col, int N);
bool solveNQueen(vector<vector<int>>& board, int row, int N);
void printSolution(vector<vector<int>>& board, int N);
int main();
```

### Recursive Solution to N-Queen Problem
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check the current column for any queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueen(vector<vector<int>>& board, int row, int N) {
    // Base case: if all queens are placed
    if (row >= N) {
        return true;
    }
    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;
            // Recur to place the rest of the queens
            if (solveNQueen(board, row + 1, N)) {
                return true;
            }
            // If placing queen in current column doesn't lead to a solution,
            // then backtrack
            board[row][col] = 0;
        }
    }
    return false;
}

void printSolution(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N = 4; // Change the size of the board as needed
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueen(board, 0, N)) {
        cout << "Solution to the N-Queen problem:" << endl;
        printSolution(board, N);
    } else {
        cout << "No solution exists for the N-Queen problem." << endl;
    }

    return 0;
}
```

### Explanation:
1. **isSafe Function**:
   - Checks if a queen can be placed on the board at `(row, col)`.
   - It ensures that no queen is placed in the same column, and checks the upper left and right diagonals.

2. **solveNQueen Function**:
   - Recursively tries to place queens in each column of the current row.
   - If placing a queen in a column doesn't lead to a solution, it backtracks by removing the queen.

3. **printSolution Function**:
   - Prints the final board configuration with queens placed.

4. **main Function**:
   - Defines the board size `N`.
   - Calls the recursive function to solve the N-Queen problem starting from row 0.
   - Prints the solution if it exists, or indicates that no solution exists.
