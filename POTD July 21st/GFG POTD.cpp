/*
  Reverse a linked list in groups of given size
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
public:
    // Function to reverse a linked list in groups of size k
    struct node *reverse(struct node *head, int k)
    {
        if (head == NULL || k == 1)
            return head;

        struct node *dummy = new struct node(0);
        dummy->next = head;
        struct node *curr = dummy, *nex, *prev = dummy;
        int count = 0;

        // Get the total number of nodes in the linked list
        while (curr->next != NULL)
        {
            count++;
            curr = curr->next;
        }

        // Continue reversing the linked list in groups of k until no nodes are left
        while (count >= k)
        {
            curr = prev->next;
            nex = curr->next;
            for (int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            count -= k;
        }

        return dummy->next;
    }
};
