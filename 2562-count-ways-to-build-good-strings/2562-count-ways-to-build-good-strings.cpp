class Solution {
public:

    int mod = 1e9 + 7;
    int dp[100001];
    int solve(int size,int zero, int one,int low,int high)
    {
        if(size>high) return 0;
        if(dp[size]!=-1) return dp[size];
        int count = 0;
        if(size>=low && size<=high) count++;
        count += solve(size + zero, zero, one, low, high)%mod;
        count += solve(size + one, zero, one, low, high)%mod;
        return dp[size] = (count)%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(0,zero,one,low,high); 
    }
};