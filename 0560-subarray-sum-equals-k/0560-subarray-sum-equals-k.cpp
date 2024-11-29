class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefixSum = 0;
        int count = 0;    
        
        for(auto i : nums)
        {
            prefixSum += i;
            if(prefixSum == k)
                count++;
            if(mp.find(prefixSum - k)!= mp.end())
            {
                count+=mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        
        return count;
    }
};