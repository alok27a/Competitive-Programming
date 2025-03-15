class Solution {
public:

    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis,int i, int j)
    {
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size();// Number of rows
        int m = grid[0].size(); // Number of cols

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                    {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        
        for(int row = 0;row<n;row++)
        {
            for(int col = 0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    bfs(grid,vis,row,col);
                }
            }
        }
        return cnt;
    }
};