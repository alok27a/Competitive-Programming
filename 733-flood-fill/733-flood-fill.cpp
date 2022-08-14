class Solution {
public:
    
   void dfs(vector<vector<int>>& adj, int i, int j, int n, int m, int color, int key){
       if(i>n-1 || i<0 || j>m-1 || j<0 || adj[i][j] != key || adj[i][j]== color){
           return;
       }
       adj[i][j]= color;
        dfs(adj, i-1,j, n, m, color, key);
        dfs(adj, i,j-1, n, m, color, key);
        dfs(adj, i+1,j, n, m, color, key);
        dfs(adj, i,j+1, n, m, color, key);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int key = image[sr][sc];
        
        dfs(image, sr, sc, n, m, color, key);
        return image;
    }
};