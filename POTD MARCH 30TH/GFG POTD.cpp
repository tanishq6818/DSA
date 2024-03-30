Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Example 1:

Input:
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
Output: 1
Example 2:

Input:
             9
              \
               10
                \
                 11
Output: 9
Your Task:
The task is to complete the function minValue() which takes root as the argument and returns the minimum element of BST. If the tree is empty, there is no minimum element, so return -1 in that case.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(1).

Constraints:
0 <= n <= 104int minValue(Node* root) {
        if (root == NULL) {
            // If the tree is empty, return -1
            return -1;
        }
        
        // Traverse the left subtree until reaching the leftmost node
        while (root->left != NULL) {
            root = root->left;
        }
        
        // Return the value of the leftmost node, which is the minimum value
        return root->data;
    }
