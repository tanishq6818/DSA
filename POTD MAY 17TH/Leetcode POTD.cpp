Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

 

Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
Example 2:



Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:



Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000

  class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // 1. Visit the left children
        root->left = removeLeafNodes(root->left, target); 

        // 2. Visit the right children
        root->right = removeLeafNodes(root->right, target); 

        // 3. check if the current node is a leaf node and its value equals target. 
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            // Delete the node by returning a nullptr to the parent, effectively disconnecting it.
            return nullptr;
        }
        // keep it untouched otherwise
        return root;
    }
};
