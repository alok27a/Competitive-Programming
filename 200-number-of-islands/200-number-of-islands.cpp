class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int n,int m,int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!='1')
            return;
        
//         Marking the element as visited
        grid[x][y] = '2';
        
//         Recursive call in all 4 direction
        dfs(grid,n,m,x+1,y);
        dfs(grid,n,m,x,y+1);
        dfs(grid,n,m,x-1,y);
        dfs(grid,n,m,x,y-1);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); // Number of rows
        
        
        if(n==0)
            return 0;
        
        int m = grid[0].size(); // Number of column
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    // cout<<"1"<<endl;
                    dfs(grid,n,m,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};