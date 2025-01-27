### Problem Statement: Print All Subsequences of a Vector of Integers

**Objective**:
Write a program to print all subsequences of a given vector of integers using recursion. A subsequence is a sequence derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Constraints**:
- The input is a vector of integers `arr`.
- Subsequences should be printed in the order they appear in the vector.
- You can assume the elements in the vector are distinct.

**Input**:
- A vector of integers `arr` representing the array.

**Output**:
- Print each subsequence on a new line.

**Example**:
```
Input:
arr = {1, 2, 3}

Output:
1
2
1 2
3
1 3
2 3
1 2 3
```

**Explanation**:
- The subsequences of the input array `{1, 2, 3}` are printed in the order they appear.
- Note that an empty subsequence is also a valid subsequence but is not required to be printed.

**Function Signature**:
```cpp
void printSubsequences(vector<int>& arr, vector<int>& output, int index);
int main();
```

**Your Task**:
1. Implement the `printSubsequences` function to recursively generate and print all subsequences.
2. Write the `main` function to define the vector and call the `printSubsequences` function.

**Solution**:
```cpp
#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(vector<int>& arr, vector<int>& output, int index) {
    // Base case: if we've reached the end of the array
    if (index == arr.size()) {
        // Print the current subsequence
        for (int num : output) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Exclude the current element and recurse
    printSubsequences(arr, output, index + 1);

    // Include the current element and recurse
    output.push_back(arr[index]);
    printSubsequences(arr, output, index + 1);
    output.pop_back(); // Backtrack to explore other subsequences
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> output;
    cout << "All subsequences of the vector are:" << endl;
    printSubsequences(arr, output, 0);
    return 0;
}
```

### Explanation:
1. **Base Case**: If we've reached the end of the array (`index == arr.size()`), print the current subsequence (`output`).
2. **Recursive Case**: For each element in the array:
   - Exclude the current element and call the function recursively.
   - Include the current element, call the function recursively, then backtrack by removing the element from `output`.

### Example Output:
For the input vector `{1, 2, 3}`, the program will print:
```
All subsequences of the vector are:

3
2
2 3
1
1 3
1 2
1 2 3
```
