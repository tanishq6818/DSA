// 1203. Sort Items by Groups Respecting Dependencies

// There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

// Return a sorted list of the items such that:

// The items that belong to the same group are next to each other in the sorted list.
// There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
// Return any solution if there is more than one solution and return an empty list if there is no solution.

 

// Example 1:



// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
// Output: [6,3,4,1,5,2,0,7]
// Example 2:

// Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
// Output: []
// Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
 

// Constraints:

// 1 <= m <= n <= 3 * 104
// group.length == beforeItems.length == n
// -1 <= group[i] <= m - 1
// 0 <= beforeItems[i].length <= n - 1
// 0 <= beforeItems[i][j] <= n - 1
// i != beforeItems[i][j]
// beforeItems[i] does not contain duplicates elements.

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = groupId;
                groupId++;
            }
        }

        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n);

        vector<vector<int>> groupGraph(groupId);
        vector<int> groupIndegree(groupId);

        for (int curr = 0; curr < n; curr++) {
            for (int prev : beforeItems[curr]) {
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;

                if (group[curr] != group[prev]) {
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupIndegree[group[curr]]++;
                }
            }
        }

        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);

        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }

        unordered_map<int, vector<int>> orderedGroups;
        for (int item : itemOrder) {
            orderedGroups[group[item]].push_back(item);
        }

        vector<int> answerList;
        for (int groupIndex : groupOrder) {
            for (int item : orderedGroups[groupIndex]) {
                answerList.push_back(item);
            }
        }

        return answerList;
    }

private:
    vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& indegree) {
        vector<int> visited;
        stack<int> stack;
        for (int key = 0; key < graph.size(); key++) {
            if (indegree[key] == 0) {
                stack.push(key);
            }
        }

        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            visited.push_back(curr);

            for (int prev : graph[curr]) {
                indegree[prev]--;
                if (indegree[prev] == 0) {
                    stack.push(prev);
                }
            }
        }

        return visited.size() == graph.size() ? visited : vector<int>();
    }
};
