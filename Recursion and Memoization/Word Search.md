### Problem: Word Search

---

**Problem Statement:**

Given an m x n grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]`, `word = "ABCCED"`
Output: `true`

**Example 2:**

Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]`, `word = "SEE"`
Output: `true`

**Example 3:**

Input: `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]`, `word = "ABCB"`
Output: `false`

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consist of only lowercase and uppercase English letters.

---

**Solution:**

```cpp
class Solution {
public:
    bool isSafe(int i, int j, int m, int n, vector<vector<char>>& board){
        if (i >= 0 && j >= 0 && i < m && j < n && board[i][j] != '0'){
            return true;
        }
        return false;
    }

    bool solve(int index, int i, int j, vector<vector<char>>& board, string word, int m, int n){
        if (index == word.size()){
            return true;
        }
        
        if (isSafe(i, j, m, n, board) && board[i][j] == word[index]){
            char ch = board[i][j];
            board[i][j] = '0';  // Mark cell as visited
            
            // Recursively search in all directions
            bool found = solve(index + 1, i + 1, j, board, word, m, n) ||
                         solve(index + 1, i - 1, j, board, word, m, n) ||
                         solve(index + 1, i, j + 1, board, word, m, n) ||
                         solve(index + 1, i, j - 1, board, word, m, n);
            
            board[i][j] = ch;  // Unmark cell as visited

            return found;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (solve(0, i, j, board, word, m, n)){
                    return true;
                }
            }
        }
        return false;
    }
};
```
