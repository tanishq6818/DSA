You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root node of the modified tree after removing all the half-nodes.

Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.

Examples:

Input: tree = 5
            /   \
          7     8
        / 
      2
Output: 2 5 8
Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.
Input:  tree = 2   
              / \   
            7   5 
Output: 7 2 5
Explanation: Here there are no nodes which has only one child. So the tree remains same.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the binary tree)

Constraints:
1<=number of nodes<=104
   Node* RemoveHalfNodes(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        // Recursively remove half nodes from left and right subtrees
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        
        // Check if the current node is a half node
        if (root->left == NULL && root->right != NULL) {
            // If only right child exists, return the right child to be the new root of this subtree
            Node* newRoot = root->right;
            delete root; // Deleting the old half node
            return newRoot;
        }
        else if (root->left != NULL && root->right == NULL) {
            // If only left child exists, return the left child to be the new root of this subtree
            Node* newRoot = root->left;
            delete root; // Deleting the old half node
            return newRoot;
        }
        
        // If neither condition is met, return the current node itself
        return root;
    }
