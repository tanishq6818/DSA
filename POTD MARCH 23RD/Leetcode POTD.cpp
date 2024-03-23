You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000


  void reorderList(ListNode* head) {
        if (!head || !head->next) // Handling edge cases where the list is empty or has only one node
            return;
        
        // Step 1: Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode *prev = nullptr, *curr = slow->next, *next;
        slow->next = nullptr; // Break the list into two halves
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Step 3: Merge the first half and the reversed second half alternately
        ListNode *first = head, *second = prev, *first_next, *second_next;
        while (second) {
            first_next = first->next;
            second_next = second->next;
            
            first->next = second;
            second->next = first_next;
            
            first = first_next;
            second = second_next;
        }
    }
