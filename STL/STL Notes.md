## STL Data Structures in C++

### 1. Vectors (`std::vector`)
- **Definition**: A dynamic array that can resize itself automatically when an element is inserted or deleted.
- **Operations**:
  - `push_back(value)`: Adds an element at the end. **O(1) amortized**
  - `pop_back()`: Removes the last element. **O(1)**
  - `size()`: Returns the number of elements. **O(1)**
  - `operator[]`: Accesses an element by index. **O(1)**
- **Example Usage**:
  ```cpp
  std::vector<int> vec;
  vec.push_back(10);
  vec.pop_back();
  int x = vec.size();
  int y = vec[0];
  ```
- **Significance**: Efficient for accessing and iterating elements. Ideal for dynamic arrays when the size is not fixed.

### 2. Lists (`std::list`)
- **Definition**: A doubly linked list that allows constant time insertion and deletion from anywhere in the sequence.
- **Operations**:
  - `push_front(value)`: Adds an element at the front. **O(1)**
  - `push_back(value)`: Adds an element at the end. **O(1)**
  - `pop_front()`: Removes the first element. **O(1)**
  - `pop_back()`: Removes the last element. **O(1)**
  - `insert(position, value)`: Inserts an element before the specified position. **O(1)**
- **Example Usage**:
  ```cpp
  std::list<int> lst;
  lst.push_front(1);
  lst.push_back(2);
  lst.pop_front();
  lst.pop_back();
  auto it = lst.insert(lst.begin(), 3);
  ```
- **Significance**: Efficient for insertions/deletions. Useful when frequent addition/removal of elements is required.

### 3. Deques (`std::deque`)
- **Definition**: A double-ended queue that allows insertion and deletion at both ends.
- **Operations**:
  - `push_front(value)`: Adds an element at the front. **O(1) amortized**
  - `push_back(value)`: Adds an element at the end. **O(1) amortized**
  - `pop_front()`: Removes the first element. **O(1) amortized**
  - `pop_back()`: Removes the last element. **O(1) amortized**
  - `size()`: Returns the number of elements. **O(1)**
- **Example Usage**:
  ```cpp
  std::deque<int> deq;
  deq.push_front(1);
  deq.push_back(2);
  deq.pop_front();
  deq.pop_back();
  int x = deq.size();
  ```
- **Significance**: Ideal for scenarios where both front and back operations are needed frequently.

### 4. Sets (`std::set`)
- **Definition**: A collection of unique elements, usually ordered.
- **Operations**:
  - `insert(value)`: Adds an element. **O(log n)**
  - `erase(value)`: Removes an element. **O(log n)**
  - `find(value)`: Finds an element. **O(log n)**
- **Example Usage**:
  ```cpp
  std::set<int> s;
  s.insert(10);
  s.erase(10);
  auto it = s.find(10);
  bool exists = (s.find(10) != s.end());
  ```
- **Significance**: Provides fast search and is useful when the uniqueness of elements is required.

### 5. Maps (`std::map`)
- **Definition**: An associative array that stores key-value pairs, usually ordered.
- **Operations**:
  - `insert({key, value})`: Adds a key-value pair. **O(log n)**
  - `erase(key)`: Removes a key-value pair. **O(log n)**
  - `find(key)`: Finds a value by key. **O(log n)**
  - `operator[key]`: Accesses a value by key. **O(log n)**
- **Example Usage**:
  ```cpp
  std::map<int, std::string> m;
  m.insert({1, "One"});
  m.erase(1);
  auto it = m.find(1);
  std::string val = m[1];
  ```
- **Significance**: Efficient for key-based access and operations. Useful for dictionaries or any associative data.

### 6. Unordered Sets (`std::unordered_set`)
- **Definition**: A collection of unique elements, not ordered.
- **Operations**:
  - `insert(value)`: Adds an element. **O(1) average**
  - `erase(value)`: Removes an element. **O(1) average**
  - `find(value)`: Finds an element. **O(1) average**
- **Example Usage**:
  ```cpp
  std::unordered_set<int> us;
  us.insert(10);
  us.erase(10);
  auto it = us.find(10);
  bool exists = (us.find(10) != us.end());
  ```
- **Significance**: Provides faster average-case performance compared to `std::set` due to hashing.

### 7. Unordered Maps (`std::unordered_map`)
- **Definition**: An associative array with key-value pairs, not ordered.
- **Operations**:
  - `insert({key, value})`: Adds a key-value pair. **O(1) average**
  - `erase(key)`: Removes a key-value pair. **O(1) average**
  - `find(key)`: Finds a value by key. **O(1) average**
  - `operator[key]`: Accesses a value by key. **O(1) average**
- **Example Usage**:
  ```cpp
  std::unordered_map<int, std::string> um;
  um.insert({1, "One"});
  um.erase(1);
  auto it = um.find(1);
  std::string val = um[1];
  ```
- **Significance**: Efficient for key-based access and operations with average-case constant-time complexity.

### 8. Stacks (`std::stack`)
- **Definition**: A Last In First Out (LIFO) structure.
- **Operations**:
  - `push(value)`: Adds an element to the top. **O(1)**
  - `pop()`: Removes the top element. **O(1)**
  - `top()`: Accesses the top element. **O(1)**
  - `empty()`: Checks if the stack is empty. **O(1)**
  - `size()`: Returns the number of elements. **O(1)**
- **Example Usage**:
  ```cpp
  std::stack<int> stk;
  stk.push(1);
  stk.pop();
  int topVal = stk.top();
  bool isEmpty = stk.empty();
  int size = stk.size();
  ```
- **Significance**: Used for scenarios requiring LIFO access, such as function call management.

### 9. Queues (`std::queue`)
- **Definition**: A First In First Out (FIFO) structure.
- **Operations**:
  - `push(value)`: Adds an element to the back. **O(1)**
  - `pop()`: Removes the front element. **O(1)**
  - `front()`: Accesses the front element. **O(1)**
  - `back()`: Accesses the back element. **O(1)**
  - `empty()`: Checks if the queue is empty. **O(1)**
  - `size()`: Returns the number of elements. **O(1)**
- **Example Usage**:
  ```cpp
  std::queue<int> q;
  q.push(1);
  q.pop();
  int frontVal = q.front();
  int backVal = q.back();
  bool isEmpty = q.empty();
  int size = q.size();
  ```
- **Significance**: Used for scenarios requiring FIFO access, such as task scheduling.

### 10. Priority Queues (`std::priority_queue`)
- **Definition**: A structure where elements are stored based on priority.
- **Operations**:
  - `push(value)`: Adds an element based on priority. **O(log n)**
  - `pop()`: Removes the highest-priority element. **O(log n)**
  - `top()`: Accesses the highest-priority element. **O(1)**
  - `empty()`: Checks if the queue is empty. **O(1)**
  - `size()`: Returns the number of elements. **O(1)**
- **Example Usage**:
  ```cpp
  std::priority_queue<int> pq;
  pq.push(1);
  pq.pop();
  int topVal = pq.top();
  bool isEmpty = pq.empty();
  int size = pq.size();
  ```
- **Significance**: Useful for scenarios needing prioritized processing, such as job scheduling.