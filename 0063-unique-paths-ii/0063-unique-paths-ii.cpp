class Solution {
public:
    
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        dp[i][j] = solve(obstacleGrid, m, n, i + 1, j, dp) + solve(obstacleGrid, m, n, i, j + 1, dp);
        
        return dp[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, m, n, 0, 0, dp);
    }
};
