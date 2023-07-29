// Median of BST Given a Binary Search Tree of size N, find the Median of its Node values.

// Example 1:

// Input:
//        6
//      /   \
//    3      8   
//  /  \    /  \
// 1    4  7    9
// Output: 6
// Explanation: Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8, 9. So, here median will 6.

// Example 2:

// Input:
//        6
//      /   \
//    3      8   
//  /   \    /   
// 1    4   7   
// Output: 5
// Explanation:Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8. So, here median will
// (4 + 6)/2 = 10/2 = 5.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
// Median of the BST is:

// If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
// If number of nodes are odd : then median = (N+1)/2th node.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).


// Constraints:
// 1<=N<=10000



// Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Helper function to perform inorder traversal and store elements in a vector
void inorderTraversal(Node *root, vector<int> &elements) {
    if (root == nullptr) return;
    
    inorderTraversal(root->left, elements);
    elements.push_back(root->data);
    inorderTraversal(root->right, elements);
}

float findMedian(struct Node *root) {
    // Vector to store the sorted elements from inorder traversal
    vector<int> elements;
    
    // Perform inorder traversal and store elements in the vector
    inorderTraversal(root, elements);
    
    int n = elements.size();
    // If the number of nodes is even, the median is the average of the middle two elements
    if (n % 2 == 0) {
        return (elements[n/2] + elements[n/2 - 1]) / 2.0;
    } else { // If the number of nodes is odd, the median is the middle element
        return elements[n/2];
    }
}
