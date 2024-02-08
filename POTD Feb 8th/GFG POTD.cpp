Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Example 1:

Input:
Tree:
    1
   / \
  2   3
Output:
true
Explanation:
The binary tree has a height of 2 and the leaves are at the same level.
Example 2:

Input:
Tree:
    10
   /  \
 20   30
 /  \
 10   15
Output:
false
Explanation:
The binary tree has a height of 3 and the leaves are not at the same level.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Your Task:
Implement the function check() that checks whether all the leaf nodes in the given binary tree are at the same level or not. The function takes the root node of the tree as an input and should return a boolean value (true/false) based on the condition.

Constraints:
1 ≤ n ≤ 105

bool ok(struct Node *root, int level, int *leafLevel)
    {
       
        //if tree is empty, return true
        if (root == NULL)  return true;
    
       
        //if current node is a leaf node
        if (root->left == NULL && root->right == NULL)
        {

            //if leaf level is not set yet, set it and return true
            if (*leafLevel == 0)
            {
                *leafLevel = level;
                return true;
            }
    
            //if leaf level is already set, check if current level matches leaf level
            return (level == *leafLevel);
        }
    
        //recursively check if left and right subtrees satisfy the condition
        return ok(root->left, level+1, leafLevel) &&
               ok(root->right, level+1, leafLevel);
    }
    
    
    //Function to check if all leaf nodes are at the same level.
    bool check(struct Node *root)
    {
       int level = 0, leafLevel = 0;
       //call helper function and return the result
       return ok(root, level, &leafLevel);
    }
