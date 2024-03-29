A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

 

Example 1:


Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
Example 2:


Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.
Example 3:


Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 106class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* current = root;
        return dfs(current, 0);
    }

private:
    vector<int> prev;
    bool dfs(TreeNode* current, size_t level) {
        // Base case, an empty tree is Even-Odd
        if (current == nullptr) {
            return true;
        }

        // Compare the parity of current and level
        if (current->val % 2 == level % 2) {
            return false;
        }

        // Resize prev to make room for the new level
        prev.resize(max(prev.size(), level + 1));

        // If there are previous nodes on this level, check increasing/decreasing
        // If on an even level, check that currrent's value is greater than the previous on this level
        // If on an odd level, check that current's value is less than the previous on this level
        if (prev[level] != 0 && 
                ((level % 2 == 0 && current->val <= prev[level]) ||
                 (level % 2 == 1 && current->val >= prev[level]))) {
            return false;  // Not in the required order
        }

        // Add current value to prev at index level
        prev[level] = current->val;

        // Recursively call DFS on the left and right children
        return dfs(current->left, level + 1) && dfs(current->right, level + 1);
    }
};
