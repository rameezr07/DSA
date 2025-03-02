### Generate Parentheses

---

**Problem Statement:**

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

**Example 1:**

Input: `n = 3`
Output: `["((()))","(()())","(())()","()(())","()()()"]`

**Example 2:**

Input: `n = 1`
Output: `["()"]`

**Constraints:**

- `1 <= n <= 8`

---

**Solution:**

```cpp
class Solution {
public:
    void solve(string s, int open, int close, int n, vector<string>& res) {
        if (s.size() == 2 * n) {  // Base case: When string reaches length 2*n
            res.push_back(s);
            return;
        }

        // Insert '(' if we still have '(' left to use
        if (open < n) {
            solve(s + '(', open + 1, close, n, res);
        }

        // Insert ')' if we have unmatched '(' to close
        if (close < open) {
            solve(s + ')', open, close + 1, n, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("", 0, 0, n, res);
        return res;
    }
};
```