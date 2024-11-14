class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;    
        }
        vector<int> res;
        
        for(auto i : mp)
        {
            if(i.second > n/3)
                res.push_back(i.first);
        }
        return res;
    }
};