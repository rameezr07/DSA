### Problem Statement: Count Subsequences with Sum Equal to Target

**Objective**:
Write a program to count the number of subsequences in a given vector of integers that sum up to a specified target value using recursion.

**Constraints**:
- The input is a vector of integers `arr`.
- The target sum is an integer `target`.
- Subsequences are considered in the order they appear in the vector.
- The same subsequence should not be counted multiple times.

**Input**:
- A vector of integers `arr` representing the array.
- An integer `target` representing the target sum.

**Output**:
- An integer representing the number of subsequences that sum up to the target.

**Example**:
```
Input:
arr = {1, 2, 1}
target = 2

Output:
Number of subsequences with sum = 2 is: 2
```

**Explanation**:
- There are two subsequences in the array that sum up to `2`:
  - Subsequence 1: [1, 1]
  - Subsequence 2: [2]

**Function Signature**:
```cpp
int countSubsequences(vector<int>& arr, int index, int currentSum, int target);
int main();
```

**Your Task**:
1. Implement the `countSubsequences` function to recursively count the number of subsequences with the sum equal to the target.
2. Write the `main` function to define the vector and target, then call the `countSubsequences` function.

**Solution**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int countSubsequences(vector<int>& arr, int index, int currentSum, int target) {
    // Base case: if we've reached the end of the array
    if (index == arr.size()) {
        return (currentSum == target) ? 1 : 0;
    }

    // Include the current element and recurse
    int include = countSubsequences(arr, index + 1, currentSum + arr[index], target);
    // Exclude the current element and recurse
    int exclude = countSubsequences(arr, index + 1, currentSum, target);

    // Return the sum of both possibilities
    return include + exclude;
}

int main() {
    vector<int> arr = {1, 2, 1};
    int target = 2;
    int count = countSubsequences(arr, 0, 0, target);
    cout << "Number of subsequences with sum = " << target << " is: " << count << endl;
    return 0;
}
```

### Explanation:
1. **Base Case**:
   - If we've reached the end of the array (`index == arr.size()`), check if `currentSum` equals the `target`. If it does, return `1` (indicating a valid subsequence), otherwise return `0`.

2. **Recursive Case**:
   - Include the current element in the subsequence: call the function recursively with `currentSum + arr[index]`.
   - Exclude the current element: call the function recursively with `currentSum` unchanged.

3. **Combine Results**:
   - Return the sum of results from including and excluding the current element.

### Example Output:
For the input vector `{1, 2, 1}` and target sum `2`, the program will output:
```
Number of subsequences with sum = 2 is: 2
```
The subsequences that sum up to `2` are `[1, 1]` and `[2]`.
