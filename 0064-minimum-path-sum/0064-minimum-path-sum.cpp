class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& grid, int m, int n, int i, int j){
        if(i==m-1 && j==n-1){
            return grid[m-1][n-1];
        }
        if(i>m-1 || j>n-1){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = grid[i][j]+min(solve(dp, grid, m, n, i+1, j), solve(dp, grid, m, n, i, j+1));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m,vector<int> (n,-1));
        int ans =  solve(dp, grid, m, n, 0, 0);
        return ans;
    }

};