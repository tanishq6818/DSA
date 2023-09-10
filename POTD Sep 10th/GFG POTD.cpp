//Insert a node in a bst
Node* insert(Node* root, int data) {
        // If the tree is empty, create a new node and return it as the new root.
        if (root == NULL) {
            return new Node(data);
        }

        // Recursively insert the node in the appropriate subtree.
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }

        // Return the updated root.
        return root;
    }
