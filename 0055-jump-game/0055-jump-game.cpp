class Solution {
public:
    int dp[10001];
    bool solve(vector<int>& nums,int n,int ind)
    {
        if(ind>=n-1) return true;
        if(nums[ind] == 0) return false;
        if(dp[ind]!=-1) return dp[ind];
        
        for (int jump = 1; jump <= nums[ind]; jump++) {
            if (solve(nums, n, ind + jump)) {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false; 
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size(),0);
    }
};