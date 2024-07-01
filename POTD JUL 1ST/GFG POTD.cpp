Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given linkedlist and return the root of the tree.
The result will be judged by printing the level order traversal of the Binary tree. 
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

Examples:

Input: list = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
Input: list = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2   1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Constraints:
1 <= size(list) <= 105
1 <= node.data <= 105

  void convert(Node *head, TreeNode *&root) {
        // queue to store the parent nodes.
        queue<TreeNode *> q;

        // base case.
        if (head == NULL) {
            root = NULL;
            return;
        }

        // the first node is always the root node so we add it to the queue.
        root = new TreeNode(head->data);
        q.push(root);

        head = head->next;

        // using a loop until we reach end of the linked list.
        while (head) {
            // storing the front node from queue and removing it from queue.
            TreeNode *k = q.front();
            q.pop();

            // taking next two nodes from the linked list and adding them as
            // children of the current parent node. Pushing them into the queue
            // so that they will be parents to the future nodes.
            TreeNode *leftT = NULL;
            TreeNode *rightT = NULL;
            leftT = new TreeNode(head->data);

            q.push(leftT);
            head = head->next;
            if (head) {
                rightT = new TreeNode(head->data);
                q.push(rightT);
                head = head->next;
            }

            // assigning left and right children of parent node.
            k->left = leftT;
            k->right = rightT;
        }
    }
