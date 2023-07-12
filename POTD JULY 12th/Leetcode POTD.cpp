// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

// Example 1:

// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].
//Optimized One

bool check(int v, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &graph, vector<int> &safeNodes){
        vis[v] = 1;
        pathVis[v] = 1;
        for(auto i : graph[v]){
            if(!vis[i]){
                    if(check(i,vis,pathVis,graph,safeNodes)==true){
                        safeNodes[i]=0;
                        return true;
                    }
                }
                if(pathVis[i]){
                    safeNodes[i]=0;
                    return true;
                }
        }
        pathVis[v] = 0;
        safeNodes[v] = 1;
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> safeNodes(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                check(i,vis,pathVis,graph,safeNodes);
            }
        }
        for(int i=0;i<V;i++){
            if(safeNodes[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }

//Brute Force
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
