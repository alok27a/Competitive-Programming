class Solution {
public:
    
    int dp[101];
    
    int solve(vector<int>& nums, int n)
    {
//         Base Condit
        if(n==0)
        {
            return nums[n];
        }
        if(n<0)
        {
            return 0;
        }
        
        if(dp[n]!=-1)
            return dp[n];
     
//         Main body
        int take = solve(nums,n-2) + nums[n];
        int nottake = solve(nums,n-1);
        
        return dp[n]=max(take,nottake);
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(nums,nums.size()-1);
    }
};