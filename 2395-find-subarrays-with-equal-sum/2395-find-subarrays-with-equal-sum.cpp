class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(mp[nums[i]+nums[i+1]]) return true;
            mp[nums[i]+nums[i+1]]=true;
        }
        return false;
    }
};