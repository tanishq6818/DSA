// Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

// Example 1:

// Input:
//          5
//        /   \
//       1     1
//      /       \
//     2         2
// Output: 
// True
// Explanation: 
// Tree is mirror image of itself i.e. tree is symmetric
// Example 2:

// Input:
//          5
//        /   \
//       10     10
//      /  \     \
//     20  20     30
// Output: 
// False
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 0<=N<=105

class Solution {
public:
    // Helper function to check if two subtrees are symmetric
    bool isMirror(Node* leftSubtree, Node* rightSubtree) {
        // If both subtrees are empty, they are symmetric
        if (!leftSubtree && !rightSubtree)
            return true;

        // If one of the subtrees is empty and the other is not, they are not symmetric
        if (!leftSubtree || !rightSubtree)
            return false;

        // Check if the values of the root nodes are equal and their subtrees are symmetric
        return (leftSubtree->data == rightSubtree->data) &&
               isMirror(leftSubtree->left, rightSubtree->right) &&
               isMirror(leftSubtree->right, rightSubtree->left);
    }

    // Main function to check if the binary tree is symmetric
    bool isSymmetric(Node* root) {
        // If the tree is empty, it is symmetric
        if (!root)
            return true;

        // Check if the left and right subtrees are symmetric
        return isMirror(root->left, root->right);
    }
};
