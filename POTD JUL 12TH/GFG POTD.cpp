Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

Examples :

Input: tree = 1, target = 2
            /   \
          2     3
Output: false
Explanation: There is no root to leaf path with sum 2.
Input: tree = 1,  target = 4
            /   \
          2     3
Output: true
Explanation: The sum of path from leaf node 3 to root 1 is 4.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ number of nodes ≤ 104
1 ≤ target ≤ 106

   bool hasPathSum(Node* root, int target) {
    // Base case: If root is null, return false
    if (root == nullptr) {
        return false;
    }
    
    // Check if the current node is a leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return target == root->data;
    }
    
    // Recursively check the left and right subtrees
    // Subtract the current node's value from the target
    return hasPathSum(root->left, target - root->data) || hasPathSum(root->right, target - root->data);
}
