// Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.

// Example 1:

// Input :
//         1
//       /   \
//      3     2

// Output: 
// 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1
// Example 2:

// Input :
//        10
//       /  \
//      20   30
//     / \ 
//    40  60

// Output: 
// 40 60 20 30 10
// Explanation:
// Traversing level 2 : 40 60
// Traversing level 1 : 20 30
// Traversing level 0 : 10
// Your Task: 
// You don't need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 104

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;

    queue<Node*> q;
    stack<int> s;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        s.push(current->data);

        if (current->right != nullptr)
            q.push(current->right);
        if (current->left != nullptr)
            q.push(current->left);
    }

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}
