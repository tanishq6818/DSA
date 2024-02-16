// You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

// Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

// Example 1:

// Input:
//           5
//         /    \
//        3      7
//       /  \    /   \
//      2   4  6     8
// Output: 2 3 4 5 6 7 8
// Explanation: 
// After flattening, the tree looks
// like this
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
//              \
//               7
//                \
//                 8
// Here, left of each node points
// to NULL and right contains the
// next node.
// Example 2:

// Input:
//        5
//         \
//          8
//        /   \
//       7     9  
// Output: 5 7 8 9
// Explanation:
// After flattening, the tree looks like this:
//    5
//     \
//      7
//       \
//        8
//         \
//          9
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST as input parameter and returns the root node after transforming the tree.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= Number of nodes <= 103
// 1 <= Data of a node <= 105

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node *flattenBST(Node *root)
    {
       
    if (root == NULL)
    {
        return root;
    }
    
    // Array to store inorder traversal
    vector<int> inorderArray;
    
    inorder(root, inorderArray);

    // Create a pointer called newRoot, and store the first value of the array in it.
    Node *newRoot = new Node(inorderArray[0]);

    // Create a pointer called curr and store the newRoot in it.
    Node *curr = newRoot;

    for (int i = 1; i < inorderArray.size(); i++)
    {

        // Create a new node.
        Node *temp = new Node(inorderArray[i]);

        // Make the left child of curr as NULL and right child as the temp. And make curr = temp.
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // Make both the left and the right child of the last node as NULL.
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
    }
    void inorder(Node *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }
    
    // Recur for left sub-tree
    inorder(root->left, inorderArray);

    // Add current node data to array
    inorderArray.push_back(root->data);

    // Recur for right sub-tree
    inorder(root->right, inorderArray);
}


};
