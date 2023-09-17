Node* oddEvenLinkedList(Node* head) {
    if (!head || !head->next) {
        return head; // If the list is empty or has only one node, no change is needed.
    }

    Node* oddHead = head;
    Node* evenHead = head->next;
    Node* oddCurrent = oddHead;
    Node* evenCurrent = evenHead;

    while (evenCurrent && evenCurrent->next) {
        oddCurrent->next = evenCurrent->next; // Connect the odd node to the next odd node
        oddCurrent = oddCurrent->next;

        evenCurrent->next = oddCurrent->next; // Connect the even node to the next even node
        evenCurrent = evenCurrent->next;
    }

    oddCurrent->next = evenHead; // Connect the last odd node to the even list

    return oddHead;
}
