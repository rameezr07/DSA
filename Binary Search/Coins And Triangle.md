### Coins And Triangle

Chef belongs to a very rich family which owns many gold mines. Today, he brought **N** gold coins and decided to form a triangle using these coins. Isn't it strange?

Chef has an unusual way of forming a triangle using gold coins, which is described as follows:
1. He puts 1 coin in the 1st row.
2. Then he puts 2 coins in the 2nd row.
3. Then he puts 3 coins in the 3rd row.
4. And so on as shown in the given figure.

Chef is interested in forming a triangle with the maximum possible height using at most **N** coins. Can you tell him the maximum possible height of the triangle?

### Input
The first line of input contains a single integer **T** denoting the number of test cases.

The first and only line of each test case contains an integer **N** denoting the number of gold coins Chef has.

### Output
For each test case, output a single line containing an integer corresponding to the maximum possible height of the triangle that Chef can get.

### Constraints
- \(1 \leq T \leq 100\)
- \(1 \leq N \leq 10^9\)

### Subtasks
- Subtask 1 (48 points): \(1 \leq N \leq 10^5\)
- Subtask 2 (52 points): \(1 \leq N \leq 10^9\)

### Sample
**Input**
```
3
3
5
7
```
**Output**
```
2
2
3
```

### Explanation
- **Test 1:** Chef can't form a triangle with height > 2 as it requires at least 6 gold coins.
- **Test 2:** Chef can't form a triangle with height > 2 as it requires at least 6 gold coins.
- **Test 3:** Chef can't form a triangle with height > 3 as it requires at least 10 gold coins.

### Solution

We can use the following simple procedure to solve this problem:

```cpp
int sum(int h) {
    return (h * (h + 1) / 2);
}

void solve() {
    int n;
    cin >> n;
    int h = 1;
    while (sum(h) <= n) {
        h++;
    }
    cout << h - 1 << "\n";
}
```

### Time Complexity
The time complexity of this solution is **O(sqrt(n))**.