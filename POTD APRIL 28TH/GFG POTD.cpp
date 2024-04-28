Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list has single node, then it should return NULL.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 
1 2 4 5
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 
2 4 6 5 1
Your Task:
The task is to complete the function deleteMid() which takes head of the linkedlist  and return head of the linkedlist with middle element deleted from the linked list. If the linked list is empty or contains single element then it should return NULL.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 105
1 <= value[i] <= 109

  ListNode* deleteMid(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or contains a single element, return NULL.
        return NULL;
    }

    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    ListNode *prev_ptr = NULL;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        // Move slow_ptr one step at a time and fast_ptr two steps at a time.
        prev_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    // Delete the middle node(s).
    prev_ptr->next = slow_ptr->next;
    delete slow_ptr;

    return head;
}
