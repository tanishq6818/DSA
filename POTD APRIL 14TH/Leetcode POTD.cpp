Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0

  class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;  // If root is null, return 0
        
        int sum = 0;
        
        if (root->left) {
            // Check if the left child is a leaf
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;  // It's a left leaf, add its value
            } else {
                sum += sumOfLeftLeaves(root->left);  // Otherwise, traverse further
            }
        }
        
        sum += sumOfLeftLeaves(root->right);  // Traverse right child
        
        return sum;
    }
};
