### Problem: Multiply Strings

**Problem Statement:**

Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.

**Note:** You must not use any built-in BigInteger library or convert the inputs to integers directly.

**Example 1:**
- **Input:** `num1 = "2"`, `num2 = "3"`
- **Output:** `"6"`

**Example 2:**
- **Input:** `num1 = "123"`, `num2 = "456"`
- **Output:** `"56088"`

**Constraints:**
- The length of `num1` and `num2` is between 1 and 200 (inclusive).
- Both `num1` and `num2` consist of digits only.
- Both `num1` and `num2` do not contain any leading zeros except for the number 0 itself.

---

**Solution:**

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1 + len2, 0);
        
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        string product = "";
        for (int num : result) {
            if (!(product.empty() && num == 0)) {
                product.push_back(num + '0');
            }
        }
        
        return product.empty() ? "0" : product;
    }
};
```

---

This solution uses a vector to store the intermediate results of the multiplication. The result is then converted back to a string, and leading zeros are removed. This approach ensures the solution adheres to the constraints and does not convert the inputs to integers directly.

