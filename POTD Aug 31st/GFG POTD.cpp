// Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

// Example 1:

// Tree = 
//         4
//       /   \
//      2     6
//     / \   / \  
//    1   3 5   7

// N = 4
// Values to be deleted = {4,1,3,6}

// Input: Value to be deleted = 4
// Output:
//         5    
//       /   \
//      2     6
//     / \     \  
//    1   3     7

// Input: Value to be deleted = 1
// Output:
//         5    
//       /   \
//      2     6
//       \     \  
//        3     7

// Input: Value to be deleted = 3
// Output:
//         5    
//       /   \
//      2     6
//             \  
//              7

// Input: Value to be deleted = 6
// Output:
//         5    
//       /   \
//      2     7

// Your Task:  
// You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

// Note: The tree will be checked after each deletion. 
// If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
// If instead all deletion are successful, inorder traversal of tree will be printed.
// If every single node is deleted from tree, 'null' will be printed.

// Expected Time Complexity: O(height of tree)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ N ≤ 500 

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
