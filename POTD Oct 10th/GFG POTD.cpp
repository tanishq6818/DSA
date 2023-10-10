// Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
// Note: You have to return list in sorted order.

// Example 1:

// Input:      
//           20
//         /    \
//       8       22 
//     /   \
//    4    12 
//        /   \
//       10    14
// Target Node = 8
// K = 2
// Output: 10 14 22
// Explanation: The three nodes at distance 2
// from node 8 are 10, 14, 22.

// Example 2:

// Input:      
//          20
//        /    \
//       7      24
//     /   \
//    4     3
//         /  
//        1    
// Target Node = 7
// K = 2
// Output: 1 24
// Your Task:  
// You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.

// Expected Time Complexity: O(N*logN)
// Expected Auxiliary Space: O(Height of tree)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ data of node ≤ 109
// 1 ≤ target ≤ 109
// 1 ≤ k ≤ 20

class Solution
{
private:
    vector<int> result; // To store the result nodes

    void findKDistanceNodesFromTarget(Node* root, int k)
    {
        if (!root || k < 0)
            return;

        if (k == 0)
        {
            result.push_back(root->data);
            return;
        }

        // Recursively explore the left and right subtrees
        findKDistanceNodesFromTarget(root->left, k - 1);
        findKDistanceNodesFromTarget(root->right, k - 1);
    }

    int findTargetAndKDistanceNodes(Node* root, int target, int k)
    {
        if (!root)
            return -1; // Target not found

        if (root->data == target)
        {
            // Found the target node, now find nodes at distance k from it
            findKDistanceNodesFromTarget(root, k);
            return 0; // Distance from target to current node is 0
        }

        // Search in the left subtree
        int leftDistance = findTargetAndKDistanceNodes(root->left, target, k);
        if (leftDistance != -1)
        {
            // Check if nodes at distance k can be found in the right subtree
            if (leftDistance + 1 == k)
                result.push_back(root->data);
            else
                findKDistanceNodesFromTarget(root->right, k - leftDistance - 2);
            return leftDistance + 1;
        }

        // Search in the right subtree
        int rightDistance = findTargetAndKDistanceNodes(root->right, target, k);
        if (rightDistance != -1)
        {
            // Check if nodes at distance k can be found in the left subtree
            if (rightDistance + 1 == k)
                result.push_back(root->data);
            else
                findKDistanceNodesFromTarget(root->left, k - rightDistance - 2);
            return rightDistance + 1;
        }

        return -1; // Target not found in the current subtree
    }

public:
    vector<int> KDistanceNodes(Node* root, int target, int k)
    {
        result.clear(); // Clear the result vector

        // Find the target node and nodes at distance k from it
        findTargetAndKDistanceNodes(root, target, k);

        // Sort the result vector in ascending order
        sort(result.begin(), result.end());

        return result;
    }
};
