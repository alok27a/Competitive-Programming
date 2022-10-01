class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int res = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            
            if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]==1){
                vis[i-1][j] = vis[i][j] + 1;
                q.push({i-1, j});
                res = max(res, vis[i-1][j]);
                fresh--;
            }
            if(i+1<n && vis[i+1][j]==0 && grid[i+1][j]==1){
                vis[i+1][j] = vis[i][j] + 1;
                q.push({i+1, j});
                res = max(res, vis[i+1][j]);
                fresh--;
            }
            if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]==1){
                vis[i][j-1] = vis[i][j] + 1;
                res = max(res, vis[i][j-1]);
                q.push({i, j-1});
                fresh--;
            }
            if(j+1<m && vis[i][j+1]==0 && grid[i][j+1]==1){
                vis[i][j+1] = vis[i][j] + 1;
                res = max(res, vis[i][j+1]);
                q.push({i, j+1});
                fresh--;
            }
        }
        if(fresh) return -1;
        return res-1;
    }
};