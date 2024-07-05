Given a Binary Tree. You need to find and return the vertical width of the tree.

Examples :

Input:
         1
       /    \
      2      3
     / \    /  \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
Input:
     1
    /  \
   2    3
Output: 3
Explanation: The above tree has 3 vertical lines, hence the answer is 3.
Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(height of the tree).

Constraints:
0 <= number of nodes <= 104

  void verticalWidthUtil(Node *root, int hd, unordered_map<int, bool> &visited, int &minHd, int &maxHd) {
    if (root == NULL)
        return;
    
    // Mark the current horizontal distance as visited
    visited[hd] = true;
    
    // Recur for left and right subtrees
    verticalWidthUtil(root->left, hd - 1, visited, minHd, maxHd);
    verticalWidthUtil(root->right, hd + 1, visited, minHd, maxHd);
    
    // Update minHd and maxHd
    minHd = min(minHd, hd);
    maxHd = max(maxHd, hd);
}

int verticalWidth(Node* root) {
    if (root == NULL)
        return 0;
    
    // To store the visited nodes in a map
    unordered_map<int, bool> visited;
    int minHd = 0, maxHd = 0;
    
    // Compute the vertical width
    verticalWidthUtil(root, 0, visited, minHd, maxHd);
    
    // Count the number of unique horizontal distances
    return visited.size();
}
