// Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

// Example 1:

// Input:
// n = 8
// linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
// k = 2
// Output: 
// 1 -> 3 -> 5 -> 7
// Explanation: 
// After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.
// Example 2:

// Input:
// n = 10
// linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 
// k = 3
// Output: 
// 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
// Explanation: 
// After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
// Your Task:
// The task is to complete the function deleteK() which takes head of linked list and integer k as input parameters and delete every kth node from the linked list and return its head.

// Expected Time Complexity :  O(n)
// Expected Auxiliary Space :  O(1)

// Constraints:
// 1 <= n <= 105
// -109 <= elements of linked list <= 109
// 1 <= k <= n

Node* deleteK(Node *head, int k) {
        if (k == 1) { // Special case: if k is 1, delete all nodes
            return nullptr;
        }
        
        Node *current = head;
        Node *prev = nullptr;
        int count = 0;

        while (current != nullptr) {
            count++;
            // If count is a multiple of k, remove current node
            if (count % k == 0) {
                if (prev == nullptr) { // If current is head node
                    head = current->next;
                    delete current;
                    current = head;
                } else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }

        return head;
    }
