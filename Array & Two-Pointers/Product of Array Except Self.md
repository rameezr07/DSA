### Problem: Product of Array Except Self

**Problem Statement:**

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all elements of `nums` except `nums[i]`. The solution must satisfy the following constraints:
1. The product of any prefix or suffix of the array is guaranteed to fit in a 32-bit integer.
2. You must write an algorithm that runs in \(O(n)\) time complexity.
3. The use of division operations is not allowed.

**Examples:**
1. **Input:** `nums = [1,2,3,4]`  
   **Output:** `[24,12,8,6]`  
   **Explanation:** 
   - For index 0: \(2 \times 3 \times 4 = 24\)
   - For index 1: \(1 \times 3 \times 4 = 12\)
   - For index 2: \(1 \times 2 \times 4 = 8\)
   - For index 3: \(1 \times 2 \times 3 = 6\)

2. **Input:** `nums = [-1,1,0,-3,3]`  
   **Output:** `[0,0,9,0,0]`  
   **Explanation:** 
   - For index 0: \(1 \times 0 \times -3 \times 3 = 0\)
   - For index 2: Product of all other elements is \( (-1) \times 1 \times -3 \times 3 = 9\).

**Constraints:**
- \(2 \leq \text{nums.length} \leq 10^5\)
- \(-30 \leq \text{nums[i]} \leq 30\)
- The input guarantees that the result for each index will fit within a 32-bit integer.

**Follow-Up:**
Can you solve the problem using \(O(1)\) extra space complexity (excluding the space used to store the result)?

---

**Initial Solution:**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n), res(n);
        int p = 1, q = 1, j;

        // Compute prefix and suffix products
        for (int i = 0; i < n; i++) {
            j = n - i - 1;
            prefix[i] = p;
            p *= nums[i];
            suffix[j] = q;
            q *= nums[j];
        }

        // Compute result by multiplying prefix and suffix
        for (int i = 0; i < n; i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
```

**Explanation of Initial Solution:**
1. **Prefix Array:** Stores the product of all elements to the left of the current element. 
2. **Suffix Array:** Stores the product of all elements to the right of the current element. 
3. **Result:** Each index in the result is calculated as the product of the corresponding values in the prefix and suffix arrays.
4. **Time Complexity:** \(O(n)\) due to separate prefix, suffix, and result computations.
5. **Space Complexity:** \(O(n)\) because additional arrays `prefix` and `suffix` are used.

---

**Optimized Solution:**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // Compute prefix product in res
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        // Compute suffix product and multiply with res
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }
};
```

**Explanation of Optimized Solution:**
1. **Prefix and Suffix in One Pass:**
   - In the first pass, compute the prefix product directly into the `res` array.
   - In the second pass, compute the suffix product while simultaneously updating the `res` array.
2. **Space Optimization:** This approach avoids the need for separate `prefix` and `suffix` arrays, making the extra space complexity \(O(1)\), as only the `res` array is used.
3. **Time Complexity:** \(O(n)\) since it iterates through the array twice.

This optimized solution efficiently computes the result while adhering to both time and space complexity constraints.