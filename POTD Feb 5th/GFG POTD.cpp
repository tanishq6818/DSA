// Given a sorted circular linked list of length n, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

// Example 1:

// Input:
// n = 3
// LinkedList = 1->2->4
// (the first and last node is connected, i.e. 4 --> 1)
// data = 2
// Output: 
// 1 2 2 4
// Explanation:
// We can add 2 after the second node.
// Example 2:

// Input:
// n = 4
// LinkedList = 1->4->7->9
// (the first and last node is connected, i.e. 9 --> 1)
// data = 5
// Output: 
// 1 4 5 7 9
// Explanation:
// We can add 5 after the second node.
// Your Task:
// The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linked list.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 <= n <= 105

class Solution
{
    public:
    Node *sortedInsert(struct Node *head, int data)
    {
        struct Node* current = head;
        struct Node* new_Node = new Node(data);
        
        // Case 1 of the above algo
        if (current == NULL)
        {
          new_Node->next = new_Node;
          return new_Node;
        }
        
        // Case 2 of the above algo
        else if (current->data >= new_Node->data)
        {
            /* If value is smaller than head's value then
            we need to change next of last Node */
            while(current->next != head)
                current = current->next;
            
            current->next = new_Node;
            new_Node->next = head;
            return new_Node;
        }
        
        // Case 3 of the above algo
        else
        {
            /* Locate the Node before the point of insertion */
            while (current->next!= head &&
                current->next->data < new_Node->data)
            current = current->next;
            
            new_Node->next = current->next;
            current->next = new_Node;
            return head;
        }
    }

};
