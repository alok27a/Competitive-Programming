class Solution {
public:
    bool check(int i,int j,int row,int col)
    {
        if(i<0||j<0||i>row||j>col)
            return false;
        return true;
    }
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int,int>>q;
    vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==0)            
            {
                q.push({i,j});
                ans[i][j]=0;
            }
        }
    }
    
    int row=mat.size()-1,col=mat[0].size()-1;
    
    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
           q.pop();
       
        if(check(i+1,j,row,col)&&ans[i+1][j]==-1)
        {
            q.push({i+1,j});
            ans[i+1][j]=ans[i][j]+1;
        }
        if(check(i-1,j,row,col)&&ans[i-1][j]==-1)
        {
            q.push({i-1,j});
            ans[i-1][j]=ans[i][j]+1;
        }
        if(check(i,j+1,row,col)&&ans[i][j+1]==-1)
        {
            q.push({i,j+1});
            ans[i][j+1]=ans[i][j]+1;
        }
        if(check(i,j-1,row,col)&&ans[i][j-1]==-1)
        {
            q.push({i,j-1});
            ans[i][j-1]=ans[i][j]+1;
        }
        
    }
    return ans;
}
};
