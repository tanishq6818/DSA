// Given two binary trees, the task is to find if both of them are identical or not.
// Note: You need to return true or false, the printing is done by the driver code.

// Example 1:

// Input:
//      1          1
//    /   \      /   \
//   2     3    2     3
// Output: 
// Yes
// Explanation: 
// There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
// Example 2:

// Input:
//     1       1
//   /  \     /  \
//  2    3   3    2
// Output: 
// No
// Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <=Data of a node <= 109


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // If both trees are empty, they are identical.
        if (r1 == NULL && r2 == NULL)
            return true;

        // If one of the trees is empty and the other is not, they are not identical.
        if (r1 == NULL || r2 == NULL)
            return false;

        // Check if the current nodes have the same value.
        // Recursively check the left and right subtrees.
        return (r1->data == r2->data) &&
               isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};
