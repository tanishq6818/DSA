// Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.

// Example 1:

// Input:
//         1
//       /  \
//      2    3
// a = 2, b = 3
// Output: 
// 2
// Explanation: 
// We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3. The path followed will be: 2 -> 1 -> 3. Hence, the result is 2. 
// Example 2:

// Input:
//         11
//       /   \
//      22  33
//     /  \  /  \
//   44 55 66 77
// a = 77, b = 22
// Output: 
// 3
// Explanation: 
// We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to reach node 22. The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 2 <= n <= 105
// 0 <= Data of a node <= 109

class Solution {
public:
    int findDist(Node* root, int a, int b) {
        Node* lcaNode = findLCA(root, a, b);
        int distanceA = findDistance(lcaNode, a, 0);
        int distanceB = findDistance(lcaNode, b, 0);
        return distanceA + distanceB;
    }

private:
    Node* findLCA(Node* root, int a, int b) {
        if (root == nullptr)
            return nullptr;

        if (root->data == a || root->data == b)
            return root;

        Node* leftLCA = findLCA(root->left, a, b);
        Node* rightLCA = findLCA(root->right, a, b);

        if (leftLCA && rightLCA)
            return root;

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }

    int findDistance(Node* root, int target, int distance) {
        if (root == nullptr)
            return -1;

        if (root->data == target)
            return distance;

        int leftDistance = findDistance(root->left, target, distance + 1);
        int rightDistance = findDistance(root->right, target, distance + 1);

        return (leftDistance != -1) ? leftDistance : rightDistance;
    }
};
