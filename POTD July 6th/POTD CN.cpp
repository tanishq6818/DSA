//Binary LInked Lists To integer
int binaryToInteger(int n, Node *head) {
    //    Write your code here
    int result = 0;
    
    // Traverse the linked list
    while (head != nullptr) {
        // Multiply the current result by 2 and add the data of the current node
        result = result * 2 + head->data;
        
        // Move to the next node
        head = head->next;
    }
    
    return result;
}
