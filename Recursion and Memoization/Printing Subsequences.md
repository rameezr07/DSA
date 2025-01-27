## Print all subsequences of a vector of integers:

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
