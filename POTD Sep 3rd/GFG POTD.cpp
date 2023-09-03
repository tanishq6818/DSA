bool isIsomorphic(Node *root1, Node *root2) {
        // Base cases
        if (!root1 && !root2) // Both trees are empty
            return true;
        if (!root1 || !root2) // One tree is empty, the other is not
            return false;

        // If the root nodes have different values, they can't be isomorphic
        if (root1->data != root2->data)
            return false;

        // Check if either of the following conditions is true:
        // 1. Both trees are isomorphic without swapping their current nodes.
        // 2. Both trees are isomorphic after swapping their current nodes.
        return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
               (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
    }
