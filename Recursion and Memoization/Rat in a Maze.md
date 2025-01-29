### Problem Statement: Rat in a Maze with Up, Down, Left, and Right Movements

**Objective**:
Write a program to find a path for a rat to move from the top-left corner to the bottom-right corner of a grid (maze). The rat can move either down, right, up, or left at any point in time. The maze contains cells that can either be open or blocked. The goal is to print one of the possible paths for the rat to reach the target, if such a path exists.

**Constraints**:
- The grid is represented as a 2D vector `maze`.
- Each cell in the grid can either be a `1` (open path) or a `0` (blocked).
- The rat starts at the top-left corner (source) `maze[0][0]`.
- The target is the bottom-right corner `maze[m-1][n-1]`.

**Input**:
- A 2D vector `maze` of size `m x n`, where `m` is the number of rows and `n` is the number of columns.

**Output**:
- Print one of the possible paths from the source to the target as a sequence of coordinates, or indicate that no path exists.

**Example**:
```
Input:
maze = [
    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [0, 1, 0, 0],
    [1, 1, 1, 1]
]

Output:
Path found:
(0, 0)
(1, 0)
(1, 1)
(2, 1)
(3, 1)
(3, 2)
(3, 3)
```

**Explanation**:
- One of the possible paths for the rat to reach the target is printed as a sequence of coordinates.

**Solution**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a move is safe
bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& path) {
    int m = maze.size();
    int n = maze[0].size();
    return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1 && path[x][y] == 0);
}

// Function to print the path
void printPath(vector<vector<int>>& path) {
    for (int i = 0; i < path.size(); ++i) {
        for (int j = 0; j < path[i].size(); ++j) {
            if (path[i][j] == 1) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

// Recursive function to find the path
bool findPath(vector<vector<int>>& maze, vector<vector<int>>& path, int x, int y) {
    int m = maze.size();
    int n = maze[0].size();

    // Base case: if destination is reached
    if (x == m - 1 && y == n - 1 && maze[x][y] == 1) {
        path[x][y] = 1;
        return true;
    }

    // Check if the current move is safe
    if (isSafe(x, y, maze, path)) {
        // Mark the cell as part of the solution path
        path[x][y] = 1;

        // Move right
        if (findPath(maze, path, x, y + 1)) {
            return true;
        }

        // Move down
        if (findPath(maze, path, x + 1, y)) {
            return true;
        }

        // Move left
        if (findPath(maze, path, x, y - 1)) {
            return true;
        }

        // Move up
        if (findPath(maze, path, x - 1, y)) {
            return true;
        }

        // Backtrack: unmark the cell
        path[x][y] = 0;
    }

    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int m = maze.size();
    int n = maze[0].size();

    vector<vector<int>> path(m, vector<int>(n, 0));

    if (findPath(maze, path, 0, 0)) {
        cout << "Path found:" << endl;
        printPath(path);
    } else {
        cout << "No path exists" << endl;
    }

    return 0;
}
```

### Explanation:
1. **Helper Function**:
   - `isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& path)`: Checks if a move to cell `(x, y)` is within boundaries, not blocked (value `1`), and not already part of the path.

2. **Recursive Function**:
   - `findPath(vector<vector<int>>& maze, vector<vector<int>>& path, int x, int y)`:
     - **Base Case**: If the destination is reached, return `true`.
     - If the move is valid, mark the cell as part of the path and recursively attempt to move right, down, left, or up.
     - If none of the moves are successful, backtrack by unmarking the cell and return `false`.

3. **Main Function**:
   - Defines the maze and initializes the path matrix.
   - Calls the recursive function starting from the top-left corner `(0, 0)`.

### Example Output:
For the given maze, the program will output the path from the source to the target:
```
Path found:
(0, 0)
(1, 0)
(1, 1)
(2, 1)
(3, 1)
(3, 2)
(3, 3)
```
Indicating a valid path exists from `(0, 0)` to `(3, 3)`.

Feel free to test it with different maze configurations! If you have any questions or need further clarifications, let me know. 😊