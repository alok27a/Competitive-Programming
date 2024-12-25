class Solution {
public:
    int solve(vector<int>& prices,int n,int ind,int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if(cap==0) return 0;
        if(ind==n) return 0;
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        
        int price = 0; 
        if(buy){
            price = max(-prices[ind] + solve(prices,n,ind+1,0,cap,dp),
                       0 + solve(prices,n,ind+1,1,cap,dp));
        } else{
            price = max(prices[ind] + solve(prices,n,ind+1,1,cap-1,dp),
                       0 + solve(prices,n,ind+1,0,cap,dp));
        }
        
        return dp[ind][buy][cap] = price;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        
        
        return solve(prices,n,0,1,2,dp);
    }
};