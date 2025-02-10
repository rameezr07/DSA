### Problem: Add Binary

**Problem Statement:**

You are given two binary strings `a` and `b`. Your task is to return their sum as a binary string.

**Example 1:**
- **Input:** `a = "11"`, `b = "1"`
- **Output:** `"100"`

**Example 2:**
- **Input:** `a = "1010"`, `b = "1011"`
- **Output:** `"10101"`

**Constraints:**
- The length of `a` and `b` is between 1 and 10^4 (inclusive).
- Both `a` and `b` consist only of '0' or '1' characters.
- Each string does not contain leading zeros except for the zero itself.

---

**Solution:**

```cpp
class Solution {
public:
    string removeLeadingZeros(const string& num) {
        size_t start = num.find_first_not_of('0'); // Find the first non-zero character

        if (start == string::npos) {
            return "0"; // If all characters are '0', return "0"
        }

        return num.substr(start); // Return substring starting from the first non-zero character
    }

    string addBinary(string a, string b) {
        int s_a = a.size(), s_b = b.size();
        int s = max(s_a, s_b) + 1;
        string res(s,'0');
        int carry = 0;
        for (int i = 0; i < s; i++) {
            int a_i = (s_a - 1 - i >= 0) ? (a[s_a - 1 - i] - '0') : 0;
            int b_i = (s_b - 1 - i >= 0) ? (b[s_b - 1 - i] - '0') : 0;
            res[s - 1 - i] = (a_i ^ b_i ^ carry) + '0';
            carry = (a_i & b_i) | (b_i & carry) | (carry & a_i);
        }
        return removeLeadingZeros(res);
    }
};
```

---

This solution handles the addition of binary strings and removes leading zeros efficiently.
