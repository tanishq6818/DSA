// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

// If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

// Note that the nodes have no values and that we only use the node numbers in this problem.

 

// Example 1:


// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
// Output: true
// Example 2:


// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
// Output: false
// Example 3:


// Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
// Output: false
 

// Constraints:

// n == leftChild.length == rightChild.length
// 1 <= n <= 104
// -1 <= leftChild[i], rightChild[i] <= n - 1

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }
        
        unordered_set<int> seen;
        stack<int> stack;
        seen.insert(root);
        stack.push(root);
        
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child != -1) {
                    if (seen.find(child) != seen.end()) {
                        return false;
                    }
                    
                    stack.push(child);
                    seen.insert(child);
                }
            }
        }
        
        return seen.size() == n;
    }
    
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
};
