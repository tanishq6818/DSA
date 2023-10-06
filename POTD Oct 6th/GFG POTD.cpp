// Given a linked list, you have to perform the following task:

// Extract the alternative nodes starting from second node.
// Reverse the extracted list.
// Append the extracted list at the end of the original list.
// Note: Try to solve the problem without using any extra memory.

// Example 1:

// Input:
// LinkedList = 10->4->9->1->3->5->9->4
// Output: 
// 10 9 3 9 4 5 1 4
// Explanation: 
// Alternative nodes in the given linked list are 4,1,5,4. Reversing the alternative nodes from the given list, and then appending them to the end of the list results in a list 10->9->3->9->4->5->1->4.
// Example 2:

// Input:
// LinkedList = 1->2->3->4->5
// Output: 
// 1 3 5 4 2 
// Explanation:
// Alternative nodes in the given linked list are 2 and 4. Reversing the alternative nodes from the given list, and then appending them to the end of the list results in a list 1->3->5->4->2.
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function rearrange() which takes the head of the linked list as input and rearranges the list as required.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 0 <= Node_value <= 109

  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        if (odd == NULL || odd->next == NULL || odd->next->next == NULL)
            // for less than 3 nodes, no rearrangement is required
            return;
        
        struct Node *even = odd->next;    // even points at the second node
        odd->next = odd->next->next;      // placing third node after first
        odd = odd->next;                  // odd now points to the third node
        even->next = NULL;                // placing NULL after second node
        
        while (odd && odd->next)
        {        
            struct Node *temp = odd->next->next;   // next odd node
            odd->next->next = even;       // connecting next even node to even
            even = odd->next;             // moving to next even node
            odd->next = temp;             // connecting odd to next odd node
            
            if (temp != NULL)
                odd = temp;
        }
        odd->next = even;
    }
};
