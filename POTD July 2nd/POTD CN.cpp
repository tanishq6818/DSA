//remove duplicates from a sorted doubly linked list

Node* removeDuplicates(Node* head) {
    if (head == nullptr)
        return head;

    Node* current = head;

    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* nextNext = current->next->next;
            delete current->next;
            current->next = nextNext;

            if (nextNext != nullptr)
                nextNext->prev = current;
        } else {
            current = current->next;
        }
    }

    return head;
}
