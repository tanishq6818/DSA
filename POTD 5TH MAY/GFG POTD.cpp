Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

Driver code will print the preorder traversal of the constructed tree.

Example 1:

Input:
n = 8
in[] = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1}
Output: 
1 2 4 8 5 3 6 7
Explanation: 
For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8
Example 2:

Input:
n = 5
in[] = {9, 5, 2, 3, 4}
post[] = {5, 9, 3, 4, 2}
Output: 
2 9 5 4 3
Explanation:  
The  resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3
Your Task:
You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 103
1 <= in[i], post[i] <= 106

   Node* buildTreeUtil(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd) {
        // Base case: if start index of inorder traversal exceeds end index, return NULL
        if (inStart > inEnd)
            return NULL;

        // The last element in postorder traversal is the root of the current subtree
        Node* root = new Node(post[postEnd]);

        // Find the index of root node in inorder traversal
        int rootIndex;
        for (int i = inStart; i <= inEnd; ++i) {
            if (in[i] == root->data) {
                rootIndex = i;
                break;
            }
        }

        // Number of elements in the left subtree
        int leftSubtreeSize = rootIndex - inStart;

        // Recursively build left and right subtrees
        root->left = buildTreeUtil(in, post, inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
        root->right = buildTreeUtil(in, post, rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);

        return root;
    }

    Node *buildTree(int in[], int post[], int n) {
        // Call the utility function to build the tree
        return buildTreeUtil(in, post, 0, n - 1, 0, n - 1);
    }
