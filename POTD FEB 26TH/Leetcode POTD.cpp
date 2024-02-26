Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

  bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base cases: if both nodes are null, they are equal
        if (p == NULL && q == NULL) {
            return true;
        }
        // If one of the nodes is null, they are not equal
        if (p == NULL || q == NULL) {
            return false;
        }
        // Check if current node values are equal
        if (p->val != q->val) {
            return false;
        }
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
