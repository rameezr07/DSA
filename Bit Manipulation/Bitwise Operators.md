### **Bitwise Operators in C++**  
Bitwise operators work at the **bit level**, meaning they operate directly on binary representations of integers.

---

## **1. List of Bitwise Operators**
| Operator | Name                 | Description |
|----------|----------------------|-------------|
| `&`      | AND                  | `1 & 1 = 1`, otherwise `0` |
| `|`      | OR                   | `0 | 1 = 1`, `1 | 0 = 1`, `1 | 1 = 1` |
| `^`      | XOR (Exclusive OR)   | `1 ^ 1 = 0`, `1 ^ 0 = 1`, `0 ^ 1 = 1` |
| `~`      | NOT (Bitwise Negation) | Flips bits: `~1010` becomes `0101` |
| `<<`     | Left Shift           | Shifts bits left, multiplying by `2^n` |
| `>>`     | Right Shift          | Shifts bits right, dividing by `2^n` |

---

## **2. Examples of Bitwise Operations**
```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 5;  //  5 = 0101 (in binary)
    int b = 3;  //  3 = 0011 (in binary)

    cout << "a & b  = " << (a & b) << endl;  // AND: 0101 & 0011 = 0001  (1)
    cout << "a | b  = " << (a | b) << endl;  // OR:  0101 | 0011 = 0111  (7)
    cout << "a ^ b  = " << (a ^ b) << endl;  // XOR: 0101 ^ 0011 = 0110  (6)
    cout << "~a     = " << (~a) << endl;     // NOT: ~0101 = 1010 (in 2's complement: -6)
    cout << "a << 1 = " << (a << 1) << endl; // Left shift: 0101 << 1 = 1010 (10)
    cout << "a >> 1 = " << (a >> 1) << endl; // Right shift: 0101 >> 1 = 0010 (2)

    return 0;
}
```

---

## **3. Explanation of Each Operation**
### **1. AND (`&`)**
```cpp
int a = 5, b = 3;
cout << (a & b); // 1
```
| `a`  | 0 | 1 | 0 | 1 |
|------|---|---|---|---|
| `b`  | 0 | 0 | 1 | 1 |
| `a&b`| 0 | 0 | 0 | 1 |

Result: **`0001`** (decimal `1`)

---

### **2. OR (`|`)**
```cpp
cout << (a | b); // 7
```
| `a`  | 0 | 1 | 0 | 1 |
|------|---|---|---|---|
| `b`  | 0 | 0 | 1 | 1 |
| `a|b`| 0 | 1 | 1 | 1 |

Result: **`0111`** (decimal `7`)

---

### **3. XOR (`^`)**
```cpp
cout << (a ^ b); // 6
```
| `a`  | 0 | 1 | 0 | 1 |
|------|---|---|---|---|
| `b`  | 0 | 0 | 1 | 1 |
| `a^b`| 0 | 1 | 1 | 0 |

Result: **`0110`** (decimal `6`)

---

### **4. NOT (`~`)**
```cpp
cout << (~a); // -6 (in 2's complement representation)
```
**Binary representation of `5` (8-bit representation):**  
`00000101`  
After `~` (inverting all bits):  
`11111010` → **(2’s complement representation of `-6`)**

---

### **5. Left Shift (`<<`)**
```cpp
cout << (a << 1); // 10
```
- `a = 5` → **`0101`**
- `a << 1` → **`1010`** (shifting left by 1)

Formula:  
\[
a << n = a \times 2^n
\]
For `a << 1`:  
\[
5 \times 2^1 = 10
\]

---

### **6. Right Shift (`>>`)**
```cpp
cout << (a >> 1); // 2
```
- `a = 5` → **`0101`**
- `a >> 1` → **`0010`** (shifting right by 1)

Formula:  
\[
a >> n = a / 2^n
\]
For `a >> 1`:  
\[
5 / 2^1 = 2
\]

---

## **4. Use Cases of Bitwise Operators**
1. **Checking if a number is even or odd** (`n & 1` → 0 for even, 1 for odd)
2. **Swapping numbers without using extra memory** (`a = a ^ b; b = a ^ b; a = a ^ b;`)
3. **Checking if a number is a power of 2** (`(n & (n - 1)) == 0`)
4. **Multiplication and division by powers of 2** (Using `<<` and `>>`)
5. **Efficiently setting/clearing bits in bit manipulation**

---