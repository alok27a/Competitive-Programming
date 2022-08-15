class Solution {
public:
    
    void bfs(unordered_map<int,list<int>> &adj,vector<int> &res,int src,vector<bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        
        while(!q.empty())
        {
            int u = q.front();
            res.push_back(u);
            q.pop();
            
            for(auto v : adj[u])
            {
                if(visited[v]!=true)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,list<int>> mp;
        
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                int u = rooms[i][j];
                mp[i].push_back(u);
            }
        }
        vector<int> res;
        int n = rooms.size();
        vector<bool> visited(n,false);
        bfs(mp,res,0,visited);
        
        if(res.size()!=n)
            return false;
        return true;
    }
};