// Given a linked list of 0s, 1s and 2s, sort it.
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Example 1:
// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2
// Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

Node* segregate(Node *head) {
        if (!head || !head->next)
            return head;

        Node* zeroHead = new Node(0); // Dummy head for the list of 0s
        Node* oneHead = new Node(0);  // Dummy head for the list of 1s
        Node* twoHead = new Node(0);  // Dummy head for the list of 2s

        Node* zeroPtr = zeroHead;
        Node* onePtr = oneHead;
        Node* twoPtr = twoHead;

        Node* curr = head;

        while (curr) {
            if (curr->data == 0) {
                zeroPtr->next = curr;
                zeroPtr = zeroPtr->next;
            } else if (curr->data == 1) {
                onePtr->next = curr;
                onePtr = onePtr->next;
            } else {
                twoPtr->next = curr;
                twoPtr = twoPtr->next;
            }

            curr = curr->next;
        }

        // Connect the three lists
        zeroPtr->next = (oneHead->next) ? oneHead->next : twoHead->next;
        onePtr->next = twoHead->next;
        twoPtr->next = nullptr;

        // Get the head of the sorted linked list
        head = zeroHead->next;

        // Free the dummy heads
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
