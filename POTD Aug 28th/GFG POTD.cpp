//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
  if (head == NULL)
        return NULL;
    
    Node *current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
    return head;
}
