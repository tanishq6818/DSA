#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printLeftView(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            if (i == 0) {
                // Print the leftmost node at the current level
                cout << node->data << " ";
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}
