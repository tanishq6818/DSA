int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ans;

        // Count the occurrences of each element
        for (int num : nums) {
            ans[num]++;
        }

        // Find the element with exactly one occurrence
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            if (it->second == 1) {
                return it->first;
            }
        }

        // Return -1 if no such element is found
        return -1;
    }
