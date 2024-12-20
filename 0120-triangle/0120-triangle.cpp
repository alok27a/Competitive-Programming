class Solution {
public:
    
    int solve(vector<vector<int>>& triangle,int m,int i,int j, vector<vector<int>> &dp)
    {
        if(i==m-1)
        {
            return triangle[i][j];
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int d = triangle[i][j] + solve(triangle,m,i+1,j,dp);
        int dd = triangle[i][j] + solve(triangle,m,i+1,j+1,dp); 
        return dp[i][j] = min(d,dd);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        
        return solve(triangle,triangle.size(),0,0,dp);
    }
};