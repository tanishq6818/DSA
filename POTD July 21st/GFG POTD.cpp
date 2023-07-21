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
    pair<struct node *,struct node *> helperReverse(struct node  *head,int k)
    {
        struct node  *prev=NULL,*curr=head,*next=NULL;
        while(curr && k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            k--;
        }
        return {prev,curr};
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node  *prev=NULL;
        struct node  *ans;
        int f=1;
        int c=0;
        while(head)
        {
            c++;
            pair<struct node *,struct node *> t=helperReverse(head,k);
            if(f)
                ans=t.first;
            f=0;
            if(prev)
                prev->next=t.first;
            prev=head;
            head=t.second;
        }
        return ans;
    }
};
