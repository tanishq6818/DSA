Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 

The duplicate numbers are 28, 49 and 53 which are removed from the list.
Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation: 

All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ size(list) ≤ 105

  struct Node* removeAllDuplicates(struct Node* head) {
    // Edge case: empty list or single node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Create a dummy node to handle cases where head itself may be removed
    struct Node* dummy = (struct Node*) malloc(sizeof(struct Node));
    dummy->data = -1;  // Dummy value that is not in the list
    dummy->next = head;
    
    struct Node* prev = dummy;
    struct Node* current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Skip all nodes with duplicate values
            int duplicateValue = current->data;
            while (current != NULL && current->data == duplicateValue) {
                struct Node* temp = current;
                current = current->next;
                free(temp);  // Free memory for removed nodes
            }
            prev->next = current;  // Link previous node to the next unique node
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
    
    head = dummy->next;  // Update head to the correct starting node
    free(dummy);  // Free dummy node
    
    return head;
}
