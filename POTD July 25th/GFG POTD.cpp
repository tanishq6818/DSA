// lEVEL ORDER TRAVERSAL
// Given a binary tree and the task is to find the spiral order traversal of the tree.

// Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 

// For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


 
 

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:1 3 2

// Example 2:

// Input:
//            10
//          /     \
//         20     30
//       /    \
//     40     60
// Output: 10 20 30 60 40 
// Your Task:
// The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
vector<int> findSpiral(Node* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }

    stack<Node*> s1; // stack for even levels (right to left)
    stack<Node*> s2; // stack for odd levels (left to right)

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            result.push_back(current->data);

            if (current->right) {
                s2.push(current->right);
            }
            if (current->left) {
                s2.push(current->left);
            }
        }

        while (!s2.empty()) {
            Node* current = s2.top();
            s2.pop();
            result.push_back(current->data);

            if (current->left) {
                s1.push(current->left);
            }
            if (current->right) {
                s1.push(current->right);
            }
        }
    }

    return result;
}
