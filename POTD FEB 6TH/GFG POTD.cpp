// Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
// A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.

// Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.

// Example 1:

// Input:
// Binary tree
//         1
//       /   \
//      2     3
//    /  \   /  \
//   4   5  6    7
//           \ 
//           8
// k = 2
// Output: 
// 2
// Explanation: 
// There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.
// Example 2:

// Input:
// Binary tree
//           1
//          /
//         3
//        /
//       5
//     /  \
//    7    8
//          \
//           9
// k = 4
// Output: 
// 1
// Explanation: 
// Only one node is there which is at a distance of 4 units from the leaf node.(node 1 for leaf with value 9) 
// Your Task:
// You don't have to read input or print anything. Complete the function printKDistantfromLeaf() that takes root node and k as inputs and returns the number of nodes that are at distance k from a leaf node. 

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= n <= 105


class Solution
{
    public:
        //Function to return count of nodes at a given distance from leaf nodes.
       int check(Node* node,int k,int d){
        if(!node->left && !node->right){
            return d==k;
        }
        // if atleast one of the subtree has a leaf node at distance k then return true
        int c=0;
        if(node->left) c|=check(node->left,k,d+1);
        if(node->right) c|=check(node->right,k,d+1);
        return c;
    }
    
    int dfs(Node* node,int k){
        int ans=0;
        // if this node has a leaf node a distance k then count it
        if(check(node,k,0)) ans++;
        if(node->left) ans+=dfs(node->left,k);
        if(node->right) ans+=dfs(node->right,k);
        return ans;
    }

    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	return dfs(root,k);
    	
    }
};
