## **Recursion**

### **Definition**
Recursion is a programming technique where a function calls itself in order to solve smaller instances of the same problem until it reaches a base case. It is especially useful for problems that can be broken down into smaller, repetitive subproblems.

### **Syntax of a Recursive Function**
```cpp
returnType functionName(parameters) {
    if (base case condition) {
        // Base case
        return base case value;
    } else {
        // Recursive case
        return functionName(modified parameters);
    }
}
```

### **Base Case**
The base case is the terminating condition of the recursion. It prevents infinite recursion by providing a condition under which the recursion stops.

### **Significance**
- Simplifies complex problems by breaking them into simpler subproblems.
- Elegant and easier to implement for certain problems like tree traversal, combinatorial problems, etc.

### **Example Programs Using Recursion**

#### Example 1: Factorial Calculation
```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
```

#### Example 2: Fibonacci Sequence
```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int num = 10;
    for (int i = 0; i < num; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}
```

### **Time and Space Complexity**
- **Factorial**:
  - Time Complexity: O(n)
  - Space Complexity: O(n) (due to the call stack)
- **Fibonacci**:
  - Time Complexity: O(2^n)
  - Space Complexity: O(n) (due to the call stack)

## **Memoization**

### **Definition**
Memoization is an optimization technique used to reduce the time complexity of recursive algorithms by storing the results of expensive function calls and reusing the stored results when the same inputs occur again. 

### **How Memoization Optimizes Memory and Time**
- **Time Optimization**: By caching the results of subproblems, memoization prevents the redundant computation of the same subproblems, significantly improving time complexity.
- **Space Optimization**: While memoization uses additional space to store results, this trade-off is often worthwhile for the time savings it provides.

### **Example Programs Using Memoization**

#### Example: Fibonacci Sequence with Memoization
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case
    }
    if (memo[n] != -1) {
        return memo[n]; // Return cached result
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2); // Compute and store result
    return memo[n];
}

int main() {
    int num = 10;
    memo.resize(num + 1, -1); // Initialize memo array with -1
    for (int i = 0; i < num; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}
```

### **Time and Space Complexity**
- **Fibonacci with Memoization**:
  - Time Complexity: O(n)
  - Space Complexity: O(n) (due to the memoization array and call stack)

### **Key Takeaways**
- **Recursion** breaks down complex problems into simpler subproblems, making the solution more elegant and easier to implement.
- **Memoization** enhances the efficiency of recursive solutions by caching results, transforming exponential time complexity into linear time complexity.