bool detectCycle(Node *head) {
    if (!head || !head->next) {
        // No cycle can exist in an empty list or a list with only one node
        return false;
    }
    
    Node *slow = head;
    Node *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;         // Move slow pointer by one step
        fast = fast->next->next;   // Move fast pointer by two steps
        
        if (slow == fast) {
            // If the slow and fast pointers meet, a cycle is detected
            return true;
        }
    }
    
    // If fast pointer reaches the end of the list, no cycle exists
    return false;
}
