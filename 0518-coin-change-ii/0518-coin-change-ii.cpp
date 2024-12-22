class Solution {
public:
    int solve(vector<int>& coins, int n, int amount,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return (amount%coins[n]==0?1:0);
        }
        if(dp[n][amount]!=-1)  
            return dp[n][amount];
        int exc = solve(coins,n-1,amount, dp);
        int inc = ((coins[n]<=amount)?solve(coins,n,amount-coins[n],dp): 0); 
        return dp[n][amount] = inc+exc;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,coins.size()-1,amount,dp);
    }
};