// Helper function to perform a depth-first search and find the target node
bool findTarget(Node* root, int target, vector<Node*>& ancestors) {
    if (!root) return false;

    ancestors.push_back(root);

    if (root->data == target)
        return true;

    if (findTarget(root->left, target, ancestors) || findTarget(root->right, target, ancestors))
        return true;

    ancestors.pop_back();
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    vector<Node*> ancestors;
    
    // Find the target node and store its ancestors in the 'ancestors' vector
    if (!findTarget(root, node, ancestors))
        return -1;
    
    // If k is greater than the number of ancestors, return -1
    if (k > ancestors.size() - 1)
        return -1;

    // Return the value of the kth ancestor
    return ancestors[ancestors.size() - k - 1]->data;
}
