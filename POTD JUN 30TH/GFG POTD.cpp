Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 3  
Explanation: 
After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 2 9
Explanation:

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
2 <= size of the linked list(n) <= 105
1 <= x <= n
1 <= node.data <= 109

  Node* deleteNode(Node* head, int x) {
    if (head == NULL) return NULL;
    
    Node* curr = head;
    
    // Case 1: Delete the head node
    if (x == 1) {
        head = curr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete curr;
        return head;
    }
    
    // Traverse to the node at position x
    int pos = 1;
    while (curr != NULL && pos < x) {
        curr = curr->next;
        pos++;
    }
    
    // curr is now the node to be deleted
    if (curr != NULL) {
        // Adjust pointers of the nodes around curr
        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
        
        delete curr;
    }
    
    return head;
}
