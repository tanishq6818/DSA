int findDuplicate(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            ans^=i;
        }
        for(int i=1; i<nums.size(); i++){
            ans=ans^i;
        }
        return ans;
    }
