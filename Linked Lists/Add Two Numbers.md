* Problem: Add Two Numbers *

---

**Problem Statement:**

You have two non-empty linked lists representing two non-negative integers. The digits of these integers are stored in reverse order, with each node containing a single digit. Your task is to add the two numbers and return the sum as a linked list.

**Assumptions:**
- Both numbers do not contain any leading zero, except for the number 0 itself.

**Example 1:**
- **Input:** `l1 = [2, 4, 3]`, `l2 = [5, 6, 4]`
- **Output:** `[7, 0, 8]`
- **Explanation:** The numbers represented are 342 and 465. Their sum is 807, which is represented as [7, 0, 8] in reverse order.

**Example 2:**
- **Input:** `l1 = [0]`, `l2 = [0]`
- **Output:** `[0]`

**Example 3:**
- **Input:** `l1 = [9, 9, 9, 9, 9, 9, 9]`, `l2 = [9, 9, 9, 9]`
- **Output:** `[8, 9, 9, 9, 0, 0, 0, 1]`

**Constraints:**
- The number of nodes in each linked list ranges from 1 to 100.
- Each node's value is between 0 and 9 (inclusive).
- The linked lists do not represent numbers with leading zeros.

---

**Solution:**

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify code
        ListNode* curr = dummy;  // Current node
        int carry = 0;  // Carry value
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with carry value
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;  // Update carry
            curr->next = new ListNode(sum % 10);  // Create new node for the sum
            curr = curr->next;
        }
        
        return dummy->next;  // Return the next node after dummy
    }
};
```

---
