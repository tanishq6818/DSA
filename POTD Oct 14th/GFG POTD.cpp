// Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

// Note: Return the common nodes in sorted order.

// Example 1:

// Input:
// BST1:
//                   5
//                /     \
//              1        10
//            /   \      /
//           0     4    7
//                       \
//                        9
// BST2:
//                 10 
//               /    \
//              7     20
//            /   \ 
//           4     9
// Output: 4 7 9 10

// Example 2:

// Input:
// BST1:
//      10
//     /  \
//    2   11
//   /  \
//  1   3
// BST2:
//        2
//      /  \
//     1    3
// Output: 1 2 3
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findCommon() that takes roots of the two BSTs as input parameters and returns a list of integers containing the common nodes in sorted order. 

// Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
// Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the heights of the 2 BSTs.

// Constraints:
// 1 <= Number of Nodes <= 105
// 1 <= Node data <= 109


void inOrderTraversal(Node* root, vector<int>& result) {
    stack<Node*> s;
    Node* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        result.push_back(current->data);

        current = current->right;
    }
}

vector<int> findCommon(Node* root1, Node* root2) {
    vector<int> result;
    vector<int> inOrder1, inOrder2;

    // Perform in-order traversal of both BSTs and store the values in vectors.
    inOrderTraversal(root1, inOrder1);
    inOrderTraversal(root2, inOrder2);

    int i = 0, j = 0;

    // Compare the values in the two vectors and add common elements to the result.
    while (i < inOrder1.size() && j < inOrder2.size()) {
        if (inOrder1[i] < inOrder2[j]) {
            i++;
        } else if (inOrder1[i] > inOrder2[j]) {
            j++;
        } else {
            result.push_back(inOrder1[i]);
            i++;
            j++;
        }
    }

    return result;
}
