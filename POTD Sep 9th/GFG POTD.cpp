// Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4
// Example 2:

// Input:
//        9
//         \ 
//           10
// K = 1
// Output: 10
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

// Constraints:
// 1 <= N <= 105
// 1 <= K <= N
void kthLargestUtil(Node *root, int &K, int &result)
    {
        if (!root || K <= 0) {
            return;
        }
        
        // Traverse the right subtree first (reverse in-order)
        kthLargestUtil(root->right, K, result);
        
        // Visit the current node
        K--; // Decrement K after visiting each node
        if (K == 0) {
            result = root->data;
            return;
        }
        
        // Traverse the left subtree
        kthLargestUtil(root->left, K, result);
    }
    
    int kthLargest(Node *root, int K)
    {
        int result = -1;
        kthLargestUtil(root, K, result);
        return result;
    }
