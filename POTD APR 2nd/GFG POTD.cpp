Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

Example 1:

Input:
Input tree

Output:
10
Explanation:
There are no two nodes whose absolute difference in smaller than 10.
Example 2:

Input:
Input tree

Output:
20
Explanation:
There are no two nodes whose absolute difference in smaller than 20.
Your Task:
You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 <= n <= 105
1 <= Node->data <= 109

  class Solution
{
    int minDiff = INT_MAX;
    Node* prev = nullptr;
    
    void inOrder(Node* root) {
        if (root == nullptr) return;
        
        // Traverse the left subtree
        inOrder(root->left);
        
        // Process the current node
        if (prev != nullptr) {
            minDiff = min(minDiff, root->data - prev->data);
        }
        prev = root; // Update prev for the next iteration
        
        // Traverse the right subtree
        inOrder(root->right);
    }
    
public:
    int absolute_diff(Node *root)
    {
        inOrder(root);
        return minDiff;
    }
};
