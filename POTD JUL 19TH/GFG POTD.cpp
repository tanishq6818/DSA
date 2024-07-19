Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i]  ≤ 108

  vector<int> bit((int)1e6 + 1);

class Solution {
  public:
  
    void update(int i, int p) {
        for (; i < (int)1e6 + 1; i += i & (-i)) {
            bit[i] += p;
        }
    }

    // Get function of BIT
    int get(int i) {
        int ans = 0;
        for (; i > 0; i -= i & (-i)) {
            ans += bit[i];
        }
        return ans;
    }

    // Function to construct the lower array
    vector<int> constructLowerArray(vector<int>& a) {
        int n = a.size();
        vector<pair<int, int>> p;

        // Compressing array value
        for (int i = 0; i < n; i++) {
            p.emplace_back(a[i], i);
        }
        sort(p.begin(), p.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2) {
                 return p1.first < p2.first;
             });

        int in = 1;
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++) {
            if (hm.find(p[i].first) == hm.end()) {
                hm[p[i].first] = in++;
            }
        }
        for (int i = 0; i < n; i++) {
            a[i] = hm[a[i]];
        }
        // Compressing array values finish. Now the values in the array are from range 1
        // to 1e6.

        // Initializing our BIT array
        fill(bit.begin(), bit.end(), 0);

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = get(a[i] - 1);
            update(a[i], 1);
        }
        return ans;
    }};
