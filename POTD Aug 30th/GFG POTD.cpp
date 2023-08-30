// Given a singly linked list and an integer x.Delete xth node from the singly linked list.

// Example 1:

// Input: 1 -> 3 -> 4 
//        x = 3
// Output: 1 -> 3
// Explanation:
// After deleting the node at 3rd
// position (1-base indexing), the
// linked list is as 1 -> 3. 
// Example 2:

// Input: 1 -> 5 -> 2 -> 9 
// x = 2
// Output: 1 -> 2 -> 9
// Explanation: 
// After deleting the node at 2nd
// position (1-based indexing), the
// linked list is as 1 -> 2 -> 9.
// Your task: Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x. The function returns the head of the modified linked list.

// Constraints:
// 2 <= N <= 105
// 1 <= x <= N

Node* deleteNode(Node *head, int x)
{
    if (head == NULL) {
        return NULL; // Empty list
    }
    
    if (x == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node *prev = NULL;
    Node *current = head;
    
    for (int i = 1; current != NULL && i < x; i++) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return head; // x is greater than the length of the list
    }
    
    prev->next = current->next;
    delete current;
    
    return head;
}
