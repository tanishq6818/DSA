You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Base case, reached end of the list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Recursive call
        ListNode* nextNode = removeNodes(head->next);

        // If the next node has greater value than head delete the head
        // Return next node, which removes the current head and makes next the new head
        if (head->val < nextNode->val) {
            delete head;
            return nextNode;
        }

        // Keep the head
        head->next = nextNode;
        return head;
    }
};
