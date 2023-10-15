// Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

// Example1:

// Input:
//        30
//       /
//      20
//     /
//    10
// Output:
//      20
//    /   \
//  10     30
// Example2:

// Input:
//          4
//         /
//        3
//       /
//      2
//     /
//    1
// Output:
//       3            3           2
//     /  \         /  \        /  \
//    1    4   OR  2    4  OR  1    3   
//     \          /                  \ 
//      2        1                    4

// Your Task:
// The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of tree after converting the given BST into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself.
 
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
// Here N denotes total number of nodes in given BST.

// Constraints:
// 1 <= N <= 105
// 1 <= Node data <= 109


#include <vector>

class Solution {
public:
    Node* buildBalancedTree(Node* root) {
        // Step 1: Inorder traversal to store values in a sorted array
        std::vector<int> sortedValues;
        inorderTraversal(root, sortedValues);
        
        // Step 2: Construct the balanced BST from the sorted array
        return buildBalancedBST(sortedValues, 0, sortedValues.size() - 1);
    }

private:
    // Helper function for inorder traversal
    void inorderTraversal(Node* root, std::vector<int>& values) {
        if (root == nullptr) return;
        inorderTraversal(root->left, values);
        values.push_back(root->data);
        inorderTraversal(root->right, values);
    }

    // Helper function to construct a balanced BST from sorted array
    Node* buildBalancedBST(const std::vector<int>& sortedValues, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        Node* newNode = new Node(sortedValues[mid]);
        
        newNode->left = buildBalancedBST(sortedValues, left, mid - 1);
        newNode->right = buildBalancedBST(sortedValues, mid + 1, right);
        
        return newNode;
    }
};
