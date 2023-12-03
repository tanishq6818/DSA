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


class Solution {
public:
    int pairCount = 0;

    void findPairs(Node* root2, int diff)
    {
        if (root2 == NULL) {
            return;
        }
        if (diff > root2->data) {
            findPairs(root2->right, diff);
        }
        else {
            findPairs(root2->left, diff);
        }
        if (root2->data == diff) {
            pairCount++;
        }
    }

    void traverseTree(Node* root1, Node* root2, int sum)
    {
        if (root1 == NULL || root2 == NULL) {
            return;
        }
        traverseTree(root1->left, root2, sum);
        traverseTree(root1->right, root2, sum);
        int diff = sum - root1->data;
        findPairs(root2, diff);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {

        traverseTree(root1, root2, x);
        return pairCount;
    }
};
