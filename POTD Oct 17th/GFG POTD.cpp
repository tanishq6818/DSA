// Given a directed graph, determine whether a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here, vertex j is reachable from another vertex i means that there is a path from vertex i to j. The reachability matrix is called the transitive closure of a graph. The directed graph is represented by an adjacency matrix where there are N vertices. 

// Example 1:

// Input: N = 4
// graph = {{1, 1, 0, 1}, 
//          {0, 1, 1, 0}, 
//          {0, 0, 1, 1}, 
//          {0, 0, 0, 1}}
// Output: {{1, 1, 1, 1}, 
//          {0, 1, 1, 1}, 
//          {0, 0, 1, 1}, 
//          {0, 0, 0, 1}}
// Explanation: 
// The output list shows the reachable indexes.
// Example 2:

// Input: N = 3
// graph = {{1, 0, 0}, 
//          {0, 1, 0}, 
//          {0, 0, 1}
// Output: {{1, 0, 0}, 
//          {0, 1, 0}, 
//          {0, 0, 1}
// Explanation: 
// The output list shows the reachable indexes.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function transitiveClosure() which takes an integer N and a 2D array graph(adjacency matrix of the graph) as input parameters and returns the transitive closure of the graph in the form of 2D array.

// Expected Time Complexity: O(N3)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 100  


class Solution{
public:
    //Function to find the transitive closure of a graph.
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        //creating a 2D vector to store the reachability matrix.
        vector<vector<int>> reach(N, vector<int>(N, -1));

        //initializing reachability matrix with the given graph.
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(i == j)
                    reach[i][j] = 1;
                else
                    reach[i][j] = graph[i][j];
            }
        }

        //applying Floyd Warshall algorithm to find transitive closure.
        for(int k = 0;k < N;k++)
            for(int i = 0;i < N;i++)
                for(int j = 0;j < N;j++)
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

        //returning the reachability matrix.
        return reach;
    }
};
