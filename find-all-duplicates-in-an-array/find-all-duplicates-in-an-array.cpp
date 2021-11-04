class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i,j,n=nums.size();
        vector<int> output;
        sort(nums.begin(),nums.end());
        
        for(i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
                output.push_back(nums[i]);
        }
        
        return output;
        
    }
};