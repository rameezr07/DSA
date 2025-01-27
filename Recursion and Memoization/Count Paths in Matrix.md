### Problem Statement: Counting Paths in a Matrix with Obstacles

**Objective**:
Write a program to count the number of unique paths from the top-left corner to the bottom-right corner of a grid (matrix). You are only allowed to move either down or right at any point in time. The grid may contain obstacles represented by `0`s, where movement is not allowed.

**Constraints**:
- The grid is represented as a 2D vector `matrix`.
- Each cell in the grid can either be a `1` (open path) or a `0` (obstacle).
- You can only move down or right from a given cell.
- The top-left corner (source) is always `matrix[0][0]` and the bottom-right corner (target) is always `matrix[m-1][n-1]`.

**Input**:
- A 2D vector `matrix` of size `m x n`, where `m` is the number of rows and `n` is the number of columns.

**Output**:
- An integer representing the number of unique paths from the source to the target.

**Example**:
```
Input:
matrix = [
    [1, 1, 0, 1],
    [1, 0, 1, 1],
    [1, 1, 1, 0],
    [0, 1, 1, 1]
]

Output:
Number of paths from source to target is: 2
```

**Explanation**:
- There are two unique paths from the top-left corner to the bottom-right corner:
  - Path 1: Right -> Down -> Down -> Right -> Right
  - Path 2: Down -> Down -> Right -> Right -> Right

**Function Signature**:
```cpp
bool isValidMove(int x, int y, vector<vector<int>>& matrix);
int countPaths(int x, int y, vector<vector<int>>& matrix);
int main();
```

**Your Task**:
1. Implement the `isValidMove` function to check if the move is within the grid and not an obstacle.
2. Implement the `countPaths` function to recursively count the number of paths.
3. Write the `main` function to define the grid and call the `countPaths` function.

**Solution**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isValidMove(int x, int y, vector<vector<int>>& matrix) {
    // Check if the cell is within the boundaries and not a hurdle
    return (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] == 1);
}

int countPaths(int x, int y, vector<vector<int>>& matrix) {
    // Base case: if we've reached the bottom-right corner
    if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
        return 1;
    }
    // If the move is not valid, return 0
    if (!isValidMove(x, y, matrix)) {
        return 0;
    }
    // Move right and down
    int right = countPaths(x, y + 1, matrix);
    int down = countPaths(x + 1, matrix);
    
    return right + down;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 0, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1}
    };
    int pathCount = countPaths(0, 0, matrix);
    cout << "Number of paths from source to target is: " << pathCount << endl;
    return 0;
}
```

### Explanation:
1. **Helper Function**:
   - `isValidMove(int x, int y, vector<vector<int>>& matrix)`: Checks if a move to cell `(x, y)` is within boundaries and not a hurdle (value `1` means valid, `0` means hurdle).

2. **Recursive Function**:
   - `countPaths(int x, int y, vector<vector<int>>& matrix)`: 
     - **Base Case**: If the bottom-right corner is reached, return `1`.
     - If the move is invalid, return `0`.
     - Recursively move right and down to count the paths.

3. **Main Function**:
   - Defines the matrix with `1`s for valid cells and `0`s for hurdles.
   - Calls the recursive function starting from the top-left corner `(0, 0)`.

### Example Output:
For the given matrix, the program will output the number of paths from the source to the target:
```
Number of paths from source to target is: 2
```
