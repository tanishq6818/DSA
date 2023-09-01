// Given a binary tree and a budget. Assume you are at the root of the tree(level 1), you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.

// Example 1:

// Input: 
//                   10
//                 /    \
//                8      2
//              /      /   \
//             3      3     6
//                     \
//                      4
// and budget = 8
// Output: 2
// Explanation:
// Cost For visiting Leaf Node 3: 3
// Cost For visiting Leaf Node 4: 4
// Cost For visiting Leaf Node 6: 3
// In budget 8 one can visit Max 2 Leaf Nodes.
// Example 2:

// Input: 
//          1
//        /   \
//       2     3
//      / \   / \
//     4   5 6   7
// and budget = 5
// Output: 1
// Explanation: We can only visit either node 4 or 5.
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function getCount() which takes root node of the tree and a integer denoting the budget as input parameters and returns an integer denoting the count of visited leaf nodes of the tree.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1<=N<=105
// 1<=budget<=104
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;

//     Node(int x)
//     {
//         data = x;
//         left = NULL;
//         right = NULL;
//     }
// };
// */

class Solution
{
public:
    //Function to recursively get the path length to each leaf node and store it in the `leaf_height` vector.
    void getLeafHeightRecur(Node *node, vector<int> &leaf_height, int pathLen)
    {
        //Base case: If the node is NULL, return.
        if (node == NULL)
            return;
        
        pathLen++; //Increment the path length by 1.
        
        //If the node is a leaf node (i.e., both left and right child are NULL), add the path length to the `leaf_height` vector.
        if (node->left == NULL && node->right == NULL)
        {
            leaf_height.push_back(pathLen);
        }
        //If the node is not a leaf node, recursively call the function on its left and right child.
        else
        {
            getLeafHeightRecur(node->left, leaf_height, pathLen);
            getLeafHeightRecur(node->right, leaf_height, pathLen);
        }
    }

    //Function to count the number of paths with sum greater than or equal to `k`.
    int getCount(Node *root, int k)
    {
        vector<int> leaf_height;
        //Get the path length to each leaf node by calling the recursive function.
        getLeafHeightRecur(root, leaf_height, 0);
        sort(leaf_height.begin(), leaf_height.end()); //Sort the `leaf_height` vector in non-decreasing order.
        
        int cnt = 0; //Initialize a counter variable to keep track of the number of paths.
        for (int i = 0; i < leaf_height.size(); i++)
        {
            //If subtracting the current path length from `k` results in a negative value, return the count.
            if (k - leaf_height[i] < 0)
                return cnt;
            else
                cnt++; //Increment the counter by 1.
            
            k -= leaf_height[i]; //Subtract the current path length from `k`.
        }
        
        return cnt; //Return the count.
    }
};
