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
    string addBinary(string a, string b) {
        string result = "";  // Resultant binary string
        int carry = 0;  // Carry value
        int i = a.size() - 1;  // Pointer for string a
        int j = b.size() - 1;  // Pointer for string b

        // Iterate over both strings from the end towards the beginning
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;  // Start with the carry value
            if (i >= 0) {
                sum += a[i] - '0';  // Convert character to integer and add to sum
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';  // Convert character to integer and add to sum
                j--;
            }
            carry = sum / 2;  // Calculate new carry
            result = char(sum % 2 + '0') + result;  // Append current bit to the result
        }

        return result;  // Return the resultant binary string
    }
};
```

---