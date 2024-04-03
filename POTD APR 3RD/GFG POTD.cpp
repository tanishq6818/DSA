Given a Tree with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

Nodes x and y will always be present in the input of a tree, and x != y.

Example 1:

Input: 
Input tree

k = 2, x = 20, y = 30 
Output:
40
Explanation:
Their 2nd common ancestor is 40.
Example 2:

Input: 
Input tree

k = 2, x = 70, y = 60
Output:
-1
Explanation:
LCA of 70 and 60 is 80, which is root itself. There does not exists 2nd common ancestor in this case.
Your task :
You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.
 
Expected Time Complexity: O(Height of the Tree)
Expected Space Complexity: O(Height of the Tree)
 
Your Task :
1 <= n, k <= 105
1 <= node->data, x, y <= 109

  class Solution
{
    public:
    
    Node* LCA(Node *root, int x, int y)
    {
        // base case
        if(root==NULL)
            return NULL;
        
        //If both x and y are smaller than data at current node, we call 
        //the function recursively for finding LCA in the left subtree. 
        if(x<root->data and y<root->data)
        {
            return LCA(root->left,x,y);
        }
        //If both x and y are greater than data at current node, we call 
        //the function recursively for finding LCA in the right subtree. 
        if(x>root->data and y > root->data)
        {
            return LCA(root->right,x,y);
        }
        
        //returning the lowest common ancestor.
        return root;
    }
    
    void pathToNode(Node *root, Node *node, vector<int>&path)
    {
        path.push_back(root->data);
        if(root->data==node->data)
            return;
        else if(node->data>root->data)
            pathToNode(root->right,node,path);
        else
            pathToNode(root->left,node,path);
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        Node *lca=LCA(root,x,y);
        vector<int>path;
        pathToNode(root,lca,path);
        reverse(path.begin(),path.end());
        if(path.size()<k)
            return -1;
        return path[k-1];
    }
};
