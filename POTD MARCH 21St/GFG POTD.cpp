Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

Example 1:

Input:
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
Output:
1 3 2 4 5 6 7
Example 2:

Input:
           7
        /     \
       9      7
     /  \      /   
    8   8  6     
   /  \
  10  9 
Output:
7 7 9 8 8 6 9 10 
Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105

  class Solution{
public:
    // Function to store the zig-zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root == nullptr)
            return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true; // Flag to indicate the direction of traversal

        while (!q.empty()) {
            int size = q.size();
            stack<int> tempStack;

            // Traverse each level
            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();

                // Depending on the flag, insert the node value into the result vector
                if (leftToRight)
                    result.push_back(curr->data);
                else
                    tempStack.push(curr->data);

                // Enqueue the child nodes
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            // Add the nodes from the stack to the result vector if the traversal is from right to left
            while (!tempStack.empty()) {
                result.push_back(tempStack.top());
                tempStack.pop();
            }

            // Flip the direction of traversal for the next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};
