// Given a Binary Tree of n nodes, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (Increasing).

// Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

// Note: The root node can not have a sibling so it cannot be included in our answer.

// Example 1:

// Input :
//        37
//       /   
//     20
//     /     
//   113 

// Output: 
// 20 113
// Explanation: 
// Nodes 20 and 113 dont have any siblings.

// Example 2:

// Input :
//        1
//       / \
//      2   3 

// Output: 
// -1
// Explanation: 
// Every node has a sibling.
// Your Task:  
// You don't need to read input or print anything. Complete the function noSibling() which takes the root of the tree as input parameter and returns a list of integers containing all the nodes that don't have a sibling in sorted order. If all nodes have a sibling, then the returning list should contain only one element -1.

// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(Height of the tree)

// Constraints:
// 1 ≤ n ≤ 104

void dfs(Node* root, Node* parent, vector<int>& result) {
    if (!root) return;

    // If the current node has no sibling, add its value to the result
    if (parent && ((!parent->left && parent->right) || (parent->left && !parent->right))) {
        result.push_back(root->data);
    }

    // Recur for left and right subtrees
    dfs(root->left, root, result);
    dfs(root->right, root, result);
}

vector<int> noSibling(Node* root) {
    vector<int> result;

    // Perform DFS traversal starting from the root
    dfs(root, nullptr, result);

    // Sort the result in increasing order
    sort(result.begin(), result.end());

    // If no node without a sibling is found, return -1 in the result list
    if (result.empty()) result.push_back(-1);

    return result;
}
