// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

// Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 
// 2 1 3
// Example 2:

// Input:
//          10
//        /    \
//       20    30
//     /   \
//    40  60
// Output: 
// 40 20 60 10 30
// Your Task:
// The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

// Expected Time Complexity: O(Number of nodes).
// Expected Auxiliary Space: O(Number of nodes).

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 109

  vector<int> serialize(Node* root)
    {
        vector<int> ans;
        if (!root)
            return { -1 };
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr == NULL) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(curr->data);
            }
            if (curr != NULL) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Function to deserialize a list and construct the
    // tree.
    Node* deSerialize(vector<int>& A)
    {
        Node* root = new Node(A[0]);
        if (A.size() == 0)
            return NULL;
        if (A[0] == -1)
            return NULL;
        queue<Node*> q;
        // root->data=A[0];
        int i = 1;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            int lef = A[i++];
            if (lef == -1) {
                curr->left = NULL;
            }
            else {
                Node* leftnode = new Node(lef);
                curr->left = leftnode;
                q.push(leftnode);
            }
            int rig = A[i++];
            if (rig == -1) {
                curr->right = NULL;
            }
            else {
                Node* rightnode = new Node(rig);
                curr->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
