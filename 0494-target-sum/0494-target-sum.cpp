class Solution {
public:
    
//     S1 - S2 = K
//     S1 + S2 = S
//     absolute difference between two subsets
//     number of ways such that subset sum is - 
    
    int solve(vector<int>& nums,int n, int target)
    {
        if(target==0) return 1;
        if(n==0) return (target==nums[n]?1:0);
        
        int exc = solve(nums,n-1,target);
        int inc = (nums[n]<=target?solve(nums,n-1,target-nums[n]):0);
        return inc + exc;
    }
    
  int solve_tab(vector<int>& nums, int n, int target) {
  
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++) dp[i][0] = 1;

    if (nums[0] <= target) dp[0][nums[0]] += 1; 

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            int exc = dp[i - 1][j];
            int inc = (nums[i] <= j) ? dp[i - 1][j - nums[i]] : 0; 
            dp[i][j] = exc + inc;
        }
    }

    return dp[n - 1][target];
}

int findTargetSumWays(vector<int>& nums, int t) {
    int s = 0;
    for (auto it : nums) s += it;
    
    if (t > s || (s - t) % 2 != 0) return 0;

    int subsetSum = (s - t) / 2;

    return solve_tab(nums, nums.size(), subsetSum);
}

};