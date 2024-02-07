class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> res;
        
        if(nums.size()==2)
        {
            
            if(nums[0]+nums[1]==target)
            {
                vector<int> a;
                a.push_back(0);
                a.push_back(1);
                return a;
            }
        }
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]] = i;    
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int f = target - nums[i];
            auto match = mp.find(f);
            if( match !=mp.end() && match->second!=i)
            {
                res.push_back(i);
                res.push_back(match->second);
                break;
            }
        }
        
        return res;
    }
};