// You are given the root of a full binary tree with the following properties:

// Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
// Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
// The evaluation of a node is as follows:

// If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
// Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
// Return the boolean result of evaluating the root node.

// A full binary tree is a binary tree where each node has either 0 or 2 children.

// A leaf node is a node that has zero children.

 

// Example 1:


// Input: root = [2,1,3,null,null,0,1]
// Output: true
// Explanation: The above diagram illustrates the evaluation process.
// The AND node evaluates to False AND True = False.
// The OR node evaluates to True OR False = True.
// The root node evaluates to True, so we return true.
// Example 2:

// Input: root = [0]
// Output: false
// Explanation: The root node is a leaf node and it evaluates to false, so we return false.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 3
// Every node has either 0 or 2 children.
// Leaf nodes have a value of 0 or 1.
// Non-leaf nodes have a value of 2 or 3.


class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, bool> evaluated;

        while (!st.empty()) {
            TreeNode* topNode = st.top();

            // If the node is a leaf node, store its value in the evaluated
            // hashmap and continue
            if (!topNode->left and !topNode->right) {
                st.pop();
                evaluated[topNode] = topNode->val;
                continue;
            }

            // If both the children have already been evaluated, use their
            // values to evaluate the current node.
            if (evaluated.find(topNode->left) != evaluated.end() and
                evaluated.find(topNode->right) != evaluated.end()) {
                st.pop();
                if (topNode->val == 2) {
                    evaluated[topNode] =
                        evaluated[topNode->left] || evaluated[topNode->right];
                } else {
                    evaluated[topNode] =
                        evaluated[topNode->left] && evaluated[topNode->right];
                }
            } else {
                // If both the children are not leaf nodes, push the current
                // node along with its left and right child back into the stack.
                st.push(topNode->right);
                st.push(topNode->left);
            }
        }

        return evaluated[root] == 1;
    }
};
