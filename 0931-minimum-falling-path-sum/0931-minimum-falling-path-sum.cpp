class Solution {
public:
//     Fixed top end point ; variable bottom;
    
    int solve(vector<vector<int>>& matrix,int m,int i,int j, vector<vector<int>> &dp)
    {
        if(j>m-1 || j<0)
            return 1e7;
        
        if(i==m-1)
        {
            return matrix[i][j];
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int dl = matrix[i][j] + solve(matrix,m,i+1,j-1,dp);
        int d = matrix[i][j] + solve(matrix,m,i+1,j,dp);
        int dd = matrix[i][j] + solve(matrix,m,i+1,j+1,dp);   
        
        return dp[i][j] = min(d,min(dd,dl));
    }
    


int solve1(vector<vector<int>>& matrix, int m, vector<vector<int>>& dp)
{
    // Initialize the first row of dp with the values from the matrix
    for (int j = 0; j < m; j++) 
        dp[0][j] = matrix[0][j];

    // Fill in the dp table for the subsequent rows
    for (int i = 1; i < m; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            int u = matrix[i][j] + dp[i-1][j];  // Directly above

            int ld = INT_MAX, rd = INT_MAX;
            // Left diagonal
            if (j - 1 >= 0) 
                ld = matrix[i][j] + dp[i-1][j-1];
            // Right diagonal
            if (j + 1 < m) 
                rd = matrix[i][j] + dp[i-1][j+1];

            dp[i][j] = min(u, min(ld, rd));  // Take the minimum of the three options
        }
    }

    // Find the minimum value in the last row
    int mini = INT_MAX;
    for (int j = 0; j < m; j++) 
        mini = min(mini, dp[m-1][j]);

    return mini;
}

int minFallingPathSum(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));

    return solve1(matrix, m, dp);    
}

};