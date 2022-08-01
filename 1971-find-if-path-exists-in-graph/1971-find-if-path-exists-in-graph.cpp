class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n+1,false);
        vector<int> parent(n+1,-1);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while(!q.empty())
        {
            int u = q.front();
            cout<<u<<" ";
            q.pop();
            if(u==destination)
                return true;
            
            for(auto v : adj[u])
            {
                if(visited[v]!=true)
                {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        return false;
    }
};