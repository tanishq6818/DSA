// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

// Example 1:

// Input:
// BST1:
//        5
//      /   \
//     3     7
//    / \   / \
//   2   4 6   8
// BST2:
//        10
//      /    \
//     6      15
//    / \    /  \
//   3   8  11   18
// x = 16
// Output:
// 3
// Explanation:
// The pairs are: (5, 11), (6, 10) and (8, 8)
// Example 2:

// Input:
// BST1:
//   1
//    \
//     3
//    /
//   2
// BST2:
//     3
//    / \
//   2   4
//  /     
// 1
// x = 4
// Output:
// 3
// Explanation:
// The pairs are: (2, 2), (3, 1) and (1, 3)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes two BST's as parameter in the form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106


class Solution
{
public:
    // Helper function to perform inorder traversal and store the nodes in a stack
    void inorderTraversal(Node* root, stack<Node*>& st, bool reverseOrder)
    {
        if (!root)
            return;

        if (reverseOrder)
        {
            inorderTraversal(root->right, st, reverseOrder);
            st.push(root);
            inorderTraversal(root->left, st, reverseOrder);
        }
        else
        {
            inorderTraversal(root->left, st, reverseOrder);
            st.push(root);
            inorderTraversal(root->right, st, reverseOrder);
        }
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        // Stack to store nodes of BSTs during traversal
        stack<Node*> stack1, stack2;

        // Initialize inorder traversal stacks
        inorderTraversal(root1, stack1, false);
        inorderTraversal(root2, stack2, true);

        int count = 0;

        // Process pairs using stacks
        while (!stack1.empty() && !stack2.empty())
        {
            int sum = stack1.top()->data + stack2.top()->data;

            if (sum == x)
            {
                count++;
                stack1.pop();
                stack2.pop();
            }
            else if (sum < x)
            {
                // Move to the next greater element in stack1
                stack1.pop();
                inorderTraversal(stack1.top()->right, stack1, false);
            }
            else
            {
                // Move to the next smaller element in stack2
                stack2.pop();
                inorderTraversal(stack2.top()->left, stack2, true);
            }
        }

        return count;
    }
};
