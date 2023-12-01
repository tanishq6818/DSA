// Given a Binary Search Tree that contains unique positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means a leaf node, at which no other node can be inserted.

// Example 1:

// Input :   
//                8
//              /   \ 
//            5      9
//          /  \     
//         2    7 
//        /
//       1     
          
// Output : 
// Yes
// Explanation : 
// Node 1 is a Dead End in the given BST.
// Example 2:

// Input :     
//               8
//             /   \ 
//            7     10
//          /      /   \
//         2      9     13

// Output : 
// Yes
// Explanation : 
// Node 9 is a Dead End in the given BST.
// Your Task: You don't have to input or print anything. Complete the function isDeadEnd() which takes BST as input and returns a boolean value.

// Expected Time Complexity: O(N), where N is the number of nodes in the BST.
// Expected Space Complexity: O(N)

// Constraints:
// 1 <= N <= 1001
// 1 <= Value of Nodes <= 10001



class Solution{
  public:
// Function to create sets for leaf and non-leaf nodes
    void make(set<int> &l,set<int> &n,Node *root)
    {
        if(root==NULL)
            return;
        
        // adding current node data to the non-leaf set
        n.insert(root->data);
        
        // if current node is a leaf node, add its data to the leaf set
        if(root->left==NULL and root->right==NULL)
        {
            l.insert(root->data);
            return;
        }
        
        // recursively calling make function for left and right children
        make(l,n,root->left);
        make(l,n,root->right);
        
    }
    
    /*You are required to complete below method */
    // Function to check if a dead end exists in the binary tree
    bool isDeadEnd(Node *root)
    {
        // Creating sets for leaf and non-leaf nodes
        set<int> leaf,node;
        make(leaf,node,root);
        
        // Adding 0 to the non-leaf set
        node.insert(0);
     
        // Checking if there is a dead end by comparing adjacent nodes in the leaf set
        for(auto i = leaf.begin();i!=leaf.end();i++)
        {
            int ii = (*i);
            
            // If the node before and after the current leaf node exist in the non-leaf set, return true
            if(node.find(ii-1)!=node.end() and node.find(ii+1)!=node.end())
                return true;
        }
        
        // If no dead end found, return false
        return false;
    }
};
