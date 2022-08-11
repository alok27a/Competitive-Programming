class Solution {
public:
    
  bool ans(int n, vector<vector<int>>& dislikes,vector<int> adj[], vector<int> &color,int node)
      {    
            queue<int> q;
            q.push(node);
            color[node] = 1;      
      
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                int currCol = color[u];

                for(auto v :  adj[u])
                {
                    if(color[v] == currCol)
                    {
                        return false;
                    }

                    if(color[v]==-1)
                    {
                        color[v] = 1 - currCol;
                        q.push(v);
                    }

                }
            }
            return true;
      }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            
        vector<int> color(n,-1);
        queue<int> q;
        vector<int> adj[n];
            
        for(int i=0;i<dislikes.size();i++)
        {
            int u = dislikes[i][0]-1;
            int v = dislikes[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!ans(n,dislikes,adj,color,i))
                    return false;
            }
        }
        return true;
    }
};