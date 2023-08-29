// Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immidiate Right , but entire List on the Right)

 

// Example 1:

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:

// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
// Explanation: All the nodes except the last
// node has a greater value node on its right,
// so all the nodes except the last node must
// be removed.
// Your Task:
// The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ size of linked list ≤ 105
// 1 ≤ element of linked list ≤ 105
// Note: Try to solve the problem without using any extra space.

Node *compute(Node *head)
    {
        // First reversed the linked list
    
        Node *cur = head;
        Node *prev = NULL;
        Node *next;
    
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        head = prev;
    
        // Link list is reversed till here
    
        // Computing and deleting the nodes which have larger nodes
        // on the left
    
        Node *current = head;
    
        Node *maxNode = head;
        Node *temp;
    
         while (current != NULL && current->next != NULL)
         {
             if(current->next->data < maxNode->data)
             {
                 temp = current->next;
                 current->next = temp->next;
                 free(temp);
             }
             else
             {
                 current = current->next;
                 maxNode= current;
             }
         }
         
         // reversing list again to get required result :-
         
         cur = head;
         prev = NULL;
         next;
         while(cur!=NULL)
         {
             next = cur->next;
             cur->next = prev;
             prev = cur;
             cur = next;
         }
    
         head = prev;
         
         // head of list can be returned now
    
        return head;
    
    }
