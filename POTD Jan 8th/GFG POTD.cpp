// Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

// Example 1:

// Input:
// N = 2, M = 2
// list1 = 1->3
// list2 = 2->4
// Output:
// 4->3->2->1
// Explanation:
// After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
// Example 2:

// Input:
// N = 4, M = 3
// list1 = 5->10->15->40 
// list2 = 2->3->20
// Output:
// 40->20->15->10->5->3->2
// Explanation:
// After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
// Your Task:
// The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

// Expected Time Complexity : O(N+M)
// Expected Auxiliary Space : O(1)

// Constraints:
// 0 <= N, M <= 104
class Solution
{
    public:
    
    struct Node * mergeResult(struct Node *node1,struct Node *node2)
    {
        Node *result = NULL;
        while(node1!=NULL&&node2!=NULL)
        {
            // comparing values of nodes to determine order of merging
            if(node1->data<=node2->data)
            {
                // merging node1 with the result list
                Node *temp = node1->next;
                node1->next = result;
                result = node1;
    
                // moving to the next node in node1 list
                node1=temp;
            }else{
                // merging node2 with the result list
                Node *temp = node2->next;
                node2->next=result;
                result = node2;
    
                // moving to the next node in node2 list
                node2=temp;
            }
        }
    
        //Check if any list finished first and merge remaining nodes
    
        while(node1!=NULL)
        {
            // merging remaining nodes in node1 list with the result list
            Node *temp = node1->next;
            node1->next = result;
            result= node1;
            node1 = temp;
        }
    
        while(node2!=NULL)
        {
            // merging remaining nodes in node2 list with the result list
            Node *temp = node2->next;
            node2->next = result;
            result = node2;
            node2 = temp;
        }
        // returning the final merged list
        return result;
    }
};
