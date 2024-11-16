class Solution {
public:
    int fn(string s1, string s2, int n, int m,vector<vector<int>> &dp)
    {
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(dp[n-1][m-1]!=-1)
            return dp[n-1][m-1];
        if(s1[n-1]==s2[m-1])
        {
           return dp[n-1][m-1] = fn(s1,s2,n-1,m-1,dp);
        }
        return dp[n-1][m-1] = 1 + min(fn(s1,s2,n-1,m,dp), min(fn(s1,s2,n,m-1,dp),fn(s1,s2,n-1,m-1,dp)));
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return fn(word1,word2, word1.size(),word2.size(),dp);
    }
};