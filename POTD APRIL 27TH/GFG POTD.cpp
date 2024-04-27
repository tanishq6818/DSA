Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Example 1:

Input:
n = 8
value[] = {7,3,5,2,6,4,1,8}
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Explanation: After sorting the given
linked list in both ways, resultant
matrix will be as given in the first
two line of output, where first line
is the output for non-decreasing
order and next line is for non-
increasing order.
Example 2:

Input:
n = 5
value[] = {9,15,0,-1,0}
Output:
-1 0 0 9 15
15 9 0 0 -1
Explanation: After sorting the given
linked list in both ways, the
resultant list will be -1 0 0 9 15
in non-decreasing order and 
15 9 0 0 -1 in non-increasing order.
Your Task:
The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing. The printing is done automatically by the driver code.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(logn)

Constraints:
1 <= n <= 104
-105 <= values[i] <= 105

  class Solution {
  public:
    struct Node *merge(struct Node *first, struct Node *second) {
        // base cases when either of two halves is null.
        if (!first)
            return second;
        if (!second)
            return first;

        // comparing data in both halves and storing the smaller in result and
        // recursively calling the merge function for next node in result.
        if (first->data < second->data) {
            first->next = merge(first->next, second);
            first->next->prev = first;
            first->prev = NULL;
            // returning the resultant list.
            return first;
        } else {
            second->next = merge(first, second->next);
            second->next->prev = second;
            second->prev = NULL;
            // returning the resultant list.
            return second;
        }
    }

    // Function to split the list into two halves.
    struct Node *splitList(struct Node *head) {
        // using two pointers to find the midpoint of list
        struct Node *fast = head, *slow = head;

        // first pointer, slow moves 1 node and second pointer, fast moves
        // 2 nodes in one iteration.
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow is before the midpoint in the list, so we split the
        // list in two halves from that point.
        struct Node *temp = slow->next;
        slow->next = NULL;
        return temp;
    }

    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        if (!head || !head->next)
            return head;

        // splitting the list into two halves.
        struct Node *second = splitList(head);

        // calling the sortDoubly function recursively for both parts separately.
        head = sortDoubly(head);
        second = sortDoubly(second);

        // calling the function to merge both halves.
        return merge(head, second);
    }
};
