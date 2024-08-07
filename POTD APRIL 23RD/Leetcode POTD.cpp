A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

 vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case for a single node tree

        // Construct the adjacency list representation of the tree
        vector<unordered_set<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }

        // Initialize a queue to store leaves
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adjList[i].size() == 1) {
                leaves.push(i);
            }
        }

        // Prune leaves until only MHTs remain
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                int neighbor = *adjList[leaf].begin();
                adjList[neighbor].erase(leaf);
                if (adjList[neighbor].size() == 1) {
                    leaves.push(neighbor);
                }
            }
        }

        // Remaining nodes in the queue are the roots of MHTs
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
