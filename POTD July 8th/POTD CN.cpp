// Sample Input 1:
// 2
// 1 2 3 4 -1 -1 -1 -1 -1
// 2 4 -1 3 6 -1 -1 -1 -1 
// Sample Output 1:
// 10
// 13
// Explanation For Sample Input 1:
// For the first test case: 
// The path between Node 3 (with value 3), and Node 4 (with value 4) produces the maximum sum, i.e., 10. Hence, the maximum possible sum is 10 in this case.

// For the second test case: 
// The path between Node 3 (with value 3), and Node 4 (with value 6) produces the maximum sum, i.e., 13. Hence, the maximum possible sum is 13 in this case.
// Sample Input 2:
// 2
// 1 -1 2 -1 -1
// 5 7 8 -1 2 -1 -1 -1 -1
// Sample Output 2:
// 3
// 22


#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int maxPathSumUtil(TreeNode<int> *root, int &maxSum) {
    if (root == NULL)
        return 0;

    int leftSum = max(0, maxPathSumUtil(root->left, maxSum));
    int rightSum = max(0, maxPathSumUtil(root->right, maxSum));

    maxSum = max(maxSum, root->data + leftSum + rightSum);

    return root->data + max(leftSum, rightSum);
}

int maxPathSum(TreeNode<int> *root)
{
    // Write your code here
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;

}
