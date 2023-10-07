/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
         
       if( head->next == NULL ) return head;
       Node* prev = head ,* curr = head->next ,*next = curr->next;
       Node* head2 = curr;
       
       while(true){
           curr->next = prev;
           if(next == NULL || next->next == NULL){
               prev->next = next;
               break;
           }
           prev->next = next->next;
           
           prev = next;
           curr = next->next;
           next = curr->next;
       }
       return head2;
    }
};
