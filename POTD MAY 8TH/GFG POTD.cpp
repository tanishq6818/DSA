Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 
10 20 40 
10 20 60 
10 30 
Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)

Constraints:
1<=n<=104

  class Solution {
public:
    void findPaths(Node* root, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        if (root == nullptr)
            return;

        // Add the current node's value to the current path
        currentPath.push_back(root->data);

        // If the current node is a leaf node, add the current path to the list of all paths
        if (root->left == nullptr && root->right == nullptr) {
            allPaths.push_back(currentPath);
        } else {
            // If the current node is not a leaf node, recursively traverse its left and right subtrees
            if (root->left)
                findPaths(root->left, currentPath, allPaths);
            if (root->right)
                findPaths(root->right, currentPath, allPaths);
        }

        // Backtrack: Remove the current node from the current path to explore other paths
        currentPath.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;

        findPaths(root, currentPath, allPaths);

        return allPaths;
    }
};
