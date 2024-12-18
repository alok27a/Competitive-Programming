class Solution {
public:
    
   int helper(vector<int>& nums,int index,int i,vector<int>& dp)
    {
        if(i<index)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i]+helper(nums,index,i-2,dp),helper(nums,index,i-1,dp));
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<int> dp1(nums.size(),-1);
        // house 1 to (n-1) or  //  house index 0 to (n-2)
        int ans1 = helper(nums,0,nums.size()-2,dp1);

        vector<int> dp2(nums.size(),-1);
        // house 2 to (n) or    //  house index 1 to (n-1)
        int ans2 = helper(nums,1,nums.size()-1,dp2);
        return max(ans1,ans2);
    }
};