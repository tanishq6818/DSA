You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

 

Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"
Example 3:


Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 

Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25
  class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        queue<pair<TreeNode*, string>> nodeQueue;

        // Add root node to queue along with its value converted to a character
        nodeQueue.push({root, string(1, root->val + 'a')});

        // Perform BFS traversal until queue is empty
        while (!nodeQueue.empty()) {

            // Pop the leftmost node and its corresponding string from queue
            auto[node, currentString] = nodeQueue.front();
            nodeQueue.pop();

            // If current node is a leaf node
            if (!node->left && !node->right) {

                // Update smallest_string if it's empty or current string is smaller
                if (smallestString.empty()) {
                    smallestString = currentString;
                } else {
                    smallestString = min(smallestString, currentString);
                }
            }

            // If current node has a left child, append it to queue
            if (node->left) {
                nodeQueue.push({node->left, char(node->left->val + 'a') + currentString});
            }

            // If current node has a right child, append it to queue
            if (node->right) {
                nodeQueue.push({node->right, char(node->right->val + 'a') + currentString});
            }
        }

        return smallestString;
    }
};
