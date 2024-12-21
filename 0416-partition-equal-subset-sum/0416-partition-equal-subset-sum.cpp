class Solution {
public:
    
    bool solve(vector<int>& nums,int ind, int target, vector<vector<int>> &dp)
    {
        if(target==0) return true;
        if(ind==0) return (nums[0]==target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool exc = solve(nums,ind-1,target,dp);
        bool inc = false;
        if(nums[ind]<=target) inc = solve(nums,ind-1,target-nums[ind],dp);
        
        return dp[ind][target] = exc || inc;
    }    
    
    bool canPartition(vector<int>& nums) {
        int arr_sum = 0;
        for(auto i:nums) arr_sum+=i;
        
        int target = arr_sum/2;
        
        if(arr_sum%2!=0) return false;
        
        vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        
        return solve(nums,nums.size()-1,target,dp);
    }
};