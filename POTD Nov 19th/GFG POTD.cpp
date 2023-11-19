// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

// Note: The elements of the linked list are not necessarily distinct.

// Example 1:

// Input:
// LinkedList1 = 1->2->3->4->6
// LinkedList2 = 2->4->6->8
// Output: 2 4 6
// Explanation: For the given two
// linked list, 2, 4 and 6 are the elements
// in the intersection.
// Example 2:

// Input:
// LinkedList1 = 10->20->40->50
// LinkedList2 = 15->40
// Output: 40
// Your Task:
// You don't have to take any input of print anything. Your task is to complete the function findIntersection(), which will take head of both of the linked lists as input and should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(n+m)
// Note: n, m are the size of the respective linked lists.

// Constraints:
// 1 <= size of linked lists <= 5000
// 1 <= Data in linked list nodes <= 104

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node *p1=head1, *p2=head2;
        Node *head=NULL, *tail=NULL;
        
        while(p1 && p2)
            if(p1->data > p2->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p2 = p2->next;
            
            else if(p2->data > p1->data)
                // nodes dont match
                // moving to next node in list with smaller node
                p1 = p1->next;
            
            else
            {
                // nodes match
                
                if(head==NULL)
                    head = tail = new Node(p1->data);
                    // creating new head for intersection list
                else
                {
                    // appending new node at the end
                    tail->next = new Node(p1->data);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
                // moving to next nodes in both lists
            }
        
        return head;
    }
};
