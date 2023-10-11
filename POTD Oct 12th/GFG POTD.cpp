Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one. 

Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only argument and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
0 ≤ Number of nodes ≤ 9

class Solution {
  public:
    unordered_set<string> subtrees;
    char MARKER = '$'; 
    // This function returns empty string if tree
    // contains a duplicate subtree of size 2 or more.
    string dupSubUtil(Node *root)
    {
        string s = "";
     
        // If current node is NULL, return marker
        if (root == NULL)
            return s + MARKER;
     
        // If left subtree has a duplicate subtree.
        string lStr = dupSubUtil(root->left);
        if (lStr.compare(s) == 0)
           return s;
     
        // Do same for right subtree
        string rStr = dupSubUtil(root->right);
        if (rStr.compare(s) == 0)
           return s;
     
        // Serialize current subtree
        s = s + root->data + lStr + rStr;
     
        // If current subtree already exists in hash
        // table. [Note that size of a serialized tree
        // with single node is 3 as it has two marker
        // nodes.
        if (s.length() > 3 and 
            subtrees.find(s) != subtrees.end())
           return "";
     
        subtrees.insert(s);
     
        return s;
    }
    
    int dupSub(Node *root)
    {
    	//subtrees.clear();
    	string str = dupSubUtil(root);
     
        if(str.compare("") == 0)
            return 1;
        else
            return 0;
    }
};
