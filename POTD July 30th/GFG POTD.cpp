// Inorder Successor in BST Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
 

// Example 1:

// Input:
//       2
//     /   \
//    1     3
// K(data of x) = 2
// Output: 3 
// Explanation: 
// Inorder traversal : 1 2 3 
// Hence, inorder successor of 2 is 3.

// Example 2:

// Input:
//              20
//             /   \
//            8     22
//           / \
//          4   12
//             /  \
//            10   14
// K(data of x) = 8
// Output: 10
// Explanation:
// Inorder traversal: 4 8 10 12 14 20 22
// Hence, successor of 8 is 10.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function inOrderSuccessor(). This function takes the root node and the reference node as argument and returns the node that is inOrder successor of the reference node. If there is no successor, return null value.


// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(1).


// Constraints:
// 1 <= N <= 105, where N is number of nodes

Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        // Initialize the successor as null
        Node* successor = nullptr;
        
        while (root != nullptr) {
            if (x->data < root->data) {
                // If the data of x is less than the current root's data,
                // the successor could be in the left subtree.
                successor = root;
                root = root->left;
            } else if (x->data > root->data) {
                // If the data of x is greater than the current root's data,
                // the successor will be in the right subtree (if it exists).
                root = root->right;
            } else {
                // If the data of x matches the current root's data,
                // we found the target node, and now we need to find its successor.
                if (root->right != nullptr) {
                    // If the target node has a right subtree,
                    // the successor will be the leftmost node in that subtree.
                    root = root->right;
                    while (root->left != nullptr)
                        root = root->left;
                    successor = root;
                }
                break;
            }
        }
        
        return successor;
    }
