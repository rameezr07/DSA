### Problem: Letter Combinations of a Phone Number

---

**Problem Statement:**

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order. A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

**Example 1:**

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

**Example 2:**

Input: digits = ""
Output: []

**Example 3:**

Input: digits = "2"
Output: ["a","b","c"]

**Constraints:**

- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].

---

**Solution:**

```cpp
class Solution {
public:
    void solve(int index, string& st, int n, string digits, vector<string> mapping, vector<string>& res){
        if(index == n){
            res.push_back(st);
            return;
        }
        int digit = digits[index] - '0';
        string letters = mapping[digit - 2];
        for(int i=0; i<letters.size(); i++){
            st.push_back(letters[i]);
            solve(index+1, st, n, digits, mapping, res);
            st.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == ""){
            return res;
        }

        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string st = "";

        solve(0, st, digits.size(), digits, mapping, res);
        return res;
    }
};
```

I hope this format is what you were looking for! If you need anything else, feel free to ask.