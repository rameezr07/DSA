### Problem: Trapping Rain Water

**Problem Statement:**

Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

**Examples:**
1. **Input:** `height = [0,1,0,2,1,0,1,3,2,1,2,1]`  
   **Output:** `6`  
   **Explanation:** The elevation map has 6 units of rainwater trapped between the bars.

2. **Input:** `height = [4,2,0,3,2,5]`  
   **Output:** `9`  
   **Explanation:** The elevation map can trap 9 units of rainwater.

**Constraints:**
- \( n == \text{height.length} \)
- \( 1 \leq n \leq 2 \times 10^4 \)
- \( 0 \leq \text{height}[i] \leq 10^5 \)

---

**Initial Solution:**

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n), rmax(n), res(n, 0);
        int l = 0, r = 0;

        // Compute left max for each bar
        for (int i = 0; i < n; i++) {
            lmax[i] = l;
            l = max(l, height[i]);
        }

        // Compute right max for each bar
        for (int i = n - 1; i >= 0; i--) {
            rmax[i] = r;
            r = max(r, height[i]);
        }

        // Calculate trapped water for each bar
        for (int i = 0; i < n; i++) {
            int w = min(lmax[i], rmax[i]) - height[i];
            if (w > 0) res[i] = w;
        }

        // Sum up the total trapped water
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += res[i];
        }

        return sum;
    }
};
```

**Explanation of Initial Solution:**
1. **Left Max Array:** Tracks the maximum height to the left of each bar.
2. **Right Max Array:** Tracks the maximum height to the right of each bar.
3. **Water Trapping Calculation:** For each bar, the water trapped above it is `min(leftMax, rightMax) - height[i]` (if this value is positive).
4. **Complexity:**  
   - Time: \(O(n)\) for the three passes to compute left max, right max, and the result.
   - Space: \(O(n)\) for the `lmax` and `rmax` arrays.

---

**Optimized Solution (Two-Pointer Approach):**

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        // Two-pointer traversal
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];  // Update left max
                } else {
                    totalWater += leftMax - height[left];  // Water trapped
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];  // Update right max
                } else {
                    totalWater += rightMax - height[right];  // Water trapped
                }
                right--;
            }
        }

        return totalWater;
    }
};
```

**Explanation of Optimized Solution:**
1. **Two-Pointer Technique:**
   - Use two pointers (`left` and `right`) to traverse the elevation map.
   - Maintain `leftMax` and `rightMax` to store the maximum heights seen so far on each side.
2. **Water Trapping Calculation:**
   - At each step, the side with the smaller current height determines the trapped water:
     - If `height[left] <= height[right]`, process the left pointer.
     - Otherwise, process the right pointer.
3. **Complexity:**
   - Time: \(O(n)\) because each element is visited once.
   - Space: \(O(1)\) as no additional arrays are used.

This solution is efficient, compact, and adheres to both time and space complexity requirements. Let me know if you'd like further assistance! 🚀