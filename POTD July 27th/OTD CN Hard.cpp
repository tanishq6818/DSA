// Problem Statement

// In a social group, there are 'N' people, with unique integer ids from 0 to (N-1). We have an array of 'logs', where each logs[i]=[timestamp, idA, idB) contains a non- negative integer 'timestamp and the 'ids' of two different people. Each log represents the time in which two different people become friends.

// Let's say that person A is acquainted with person B if A is friends with B, or A is a friend of someone acquainted with B. Your task is to return the earliest time every person become acquainted with every other person. Note:

// 1) The ids are @-indexed.

// 2) Friendship is symmetric here. That is, if A is friends with B, then B is friends with A.

// 3) Return -1 If there is no such earliest time.

// For example:

// Given 'logs' =[[2, 0, 1],[3, 1, 2], [4, 2, 3]].

// The answer here would be 4: When the people with id 2 and 3 become friends, then the circle gets completed, and the time among them is 4, and because 4 is the largest time among all, the time for the circle to get completed is 4.
// Sample Input 1 :
// 2
// 4 3
// 2 0 1
// 3 1 2
// 4 2 3
// 4 2
// 2 0 1
// 3 1 2
// Sample Output 1:
// 4
// -1
// Explanation of the Sample Input 1:
// For the first test case:
// The answer here would be 4 : 
// When the people with id 2 and 3 become friends, then the circle gets completed, and the time among them is 4, and because 4 is the largest time among all, the time for the circle to get completed is 4.


// For the second test case:
// The answer will be -1 : 
// This is because there is no possible way such that the circle get completed because there no connection of the person with ‘id’ = 3.
// Sample Input 2 :
// 2
// 4 4
// 2 0 1
// 3 1 2
// 1 2 3
// 1 0 3
// 4 3
// 2 0 1
// 1 1 2
// 1 2 3
// Sample Output 2 :
// 2
// 2

#include <vector>
#include <algorithm>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }

    int getMaxGroupSize() {
        return *std::max_element(size.begin(), size.end());
    }
};

int minTime(std::vector<std::vector<int>>& logs, int n) {
    UnionFind uf(n);

    std::sort(logs.begin(), logs.end());

    int circleCount = 0;
    int earliestTime = -1;

    for (const auto& log : logs) {
        int timestamp = log[0];
        int idA = log[1];
        int idB = log[2];

        if (uf.find(idA) != uf.find(idB)) {
            uf.unite(idA, idB);
            circleCount++;
            earliestTime = timestamp;
        }

        if (circleCount == n - 1) // All people are now in the same group
            return earliestTime;
    }

    return -1;
}
