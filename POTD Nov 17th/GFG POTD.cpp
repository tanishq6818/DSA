// Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List (CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:
// 3 1 2 
// 2 1 3
// Explanation: After converting tree to CDLL
// when CDLL is is traversed from head to
// tail and then tail to head, elements
// are displayed as in the output.
// Example 2:

// Input:
//      10
//    /    \
//   20    30
//  /  \
// 40  60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40
// Explanation:After converting tree to CDLL,
// when CDLL is is traversed from head to
// tail and then tail to head, elements
// are displayed as in the output.
// Your Task:
// You don't have to take input or print anything. Complete the function bTreeToCList() that takes root as a parameter and returns the head of the list. The driver code prints the linked list twice, first time in the right order, and another time in reverse order.

// Constraints:
// 1 <= N <= 103
// 1 <= Data of a node <= 104

// Expected time complexity: O(N)

// Expected auxiliary space: O(h) , where h = height of tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
     void bTreeToCListUtil(Node *root, Node *&head, Node *&prev)
    {
        if (!root)
            return;

        // Recursively convert left subtree
        bTreeToCListUtil(root->left, head, prev);

        // Convert current node
        if (!head)
        {
            // If head is null, set it to the leftmost node
            head = root;
        }
        else
        {
            // Otherwise, set the right pointer of the previous node to the current node
            prev->right = root;
            // Set the left pointer of the current node to the previous node
            root->left = prev;
        }

        // Update the previous node to the current node
        prev = root;

        // Recursively convert right subtree
        bTreeToCListUtil(root->right, head, prev);
    }

    // Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        if (!root)
            return nullptr;

        Node *head = nullptr; // Head of the CDLL
        Node *prev = nullptr; // Previous node in in-order traversal

        // Call the utility function to perform in-order traversal and convert to CDLL
        bTreeToCListUtil(root, head, prev);

        // Make the CDLL circular by connecting the last node to the head
        prev->right = head;
        head->left = prev;

        return head;
    }
};
