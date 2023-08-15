// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

 

// Example 1:


// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]
 

ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0); // Dummy node for the list of nodes < x
        ListNode* lessPtr = lessHead; // Pointer for the list of nodes < x
        
        ListNode* greaterHead = new ListNode(0); // Dummy node for the list of nodes >= x
        ListNode* greaterPtr = greaterHead; // Pointer for the list of nodes >= x
        
        ListNode* current = head; // Pointer to traverse the original list
        
        while (current) {
            if (current->val < x) {
                lessPtr->next = current;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = current;
                greaterPtr = greaterPtr->next;
            }
            current = current->next;
        }
        
        // Disconnect the last node from the two lists
        greaterPtr->next = nullptr;
        
        // Connect the two partitioned lists
        lessPtr->next = greaterHead->next;
        
        // Get the new head of the partitioned list
        ListNode* newHead = lessHead->next;
        
        // Clean up the dummy nodes
        delete lessHead;
        delete greaterHead;
        
        return newHead;
    }
