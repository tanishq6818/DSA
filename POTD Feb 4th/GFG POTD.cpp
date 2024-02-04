// You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

// Example 1:

// Input:
// L1 = 1->0->0
// L2 = 1->2
// Output: 88
// Explanation:  
// First linked list represents 100 and the
// second one represents 12. 12 subtracted from 100
// gives us 88 as the result. It is represented
// as 8->8 in the linked list.
// Example 2:

// Input:
// L1 = 0->0->6->3
// L2 = 7->1->0
// Output: 647
// Explanation: 
// First linked list represents 0063 => 63 and 
// the second one represents 710. 63 subtracted 
// from 710 gives us 647 as the result. It is
// represented as 6->4->7 in the linked list.
// Your Task:
// You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

// n and m are the length of the two linked lists respectively.
// Expected Time Complexity:  O(n+m)
// Expected Auxiliary Space: O(n+m)

// Constraints:
// 1 <= n <= 10000
// 0 <= values represented by the linked lists < 10n
// 0 <= values represented by the linked lists < 10m

class Solution {
public:

    void printList(Node* n) {
        while (n) {
            cout << n->data;
            n = n->next;
        }
        cout << endl;
    }
    
    int length(Node* n) {
        int ret = 0;
        while (n) {
            ret++;
            n = n->next;
        }
        return ret;
    }

    Node* reverse(Node* head) {
        Node* prev =  NULL;
        Node* current = head;
        Node* next =  NULL;

        while (current !=  NULL) {
            next = current->next; // storing next node
            current->next = prev; // linking current node to previous
            prev = current; // updating prev
            current = next; // updating current
        }

        return prev;
    }

    Node* subLinkedList(Node* l1, Node* l2) {
        
        while (l1 !=  NULL && l1->data == 0) {
            l1 = l1->next;
            // removing trailing zeroes from l1
        }

        while (l2 !=  NULL && l2->data == 0) {
            l2 = l2->next;
            // removing trailing zeroes from l2
        }

        int n1 = length(l1);
        int n2 = length(l2);

        if (n1 == 0 && n2 == 0) {
            return new Node(0);
        }

        if (n2 > n1) {
            std::swap(l1, l2);
            // making sure l1 list has the bigger number
        }

        if (n1 == n2) {
            Node* t1 = l1;
            Node* t2 = l2;
            while (t1->data == t2->data) {
                // finding which number is greater
                t1 = t1->next;
                t2 = t2->next;

                if (t1 ==  NULL) {
                    return new Node(0);
                    // returning zero if both numbers are same
                }
            }

            if (t2->data > t1->data) {
                std::swap(l1, l2);
                // making sure l1 list has the bigger number
            }
        }

        l1 = reverse(l1);
        l2 = reverse(l2);

        Node* res =  NULL;
        Node* t1 = l1;
        Node* t2 = l2;

        while (t1 !=  NULL) {
            int small = 0;
            if (t2 !=  NULL) {
                small = t2->data;
                // 'small' holds the next digit of number to be subtracted
            }

            if (t1->data < small) {
                t1->next->data -= 1;
                t1->data += 10;
                // taking carry
            }

            Node* n = new Node(t1->data - small);
            // creating new node for storing difference
            n->next = res;
            res = n;

            t1 = t1->next;
            if (t2 !=  NULL) {
                t2 = t2->next;
            }
        }

        while (res->next !=  NULL && res->data == 0) {
            res = res->next;
            // removing trailing zeroes from result list
        }
        return res;
    }
};
