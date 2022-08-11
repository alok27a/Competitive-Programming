class Solution {
public:
    
    vector<int> djikstra(vector<vector<int>> adj[],int node,vector<bool> &visited,vector<int> &dis)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(0,node)); // Dist , node
        dis[node] = 0;
        
        while(!q.empty())
        {
            int u = q.front().second;
            q.pop();
            
            for(auto it : adj[u])
            {
                int v = it[0];
                int w = it[1];
                
                if(w + dis[u]<dis[v])
                {
                    dis[v] = w + dis[u];
                    q.push(make_pair(dis[v],v));
                }
            }
        }
        return dis;
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<int>> adj[n]; 
        
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int w = times[i][2];
            
            vector<int> t;
            t.push_back(v);
            t.push_back(w);
            adj[u].push_back(t);
        }
        
        vector<bool> visited(n,false);
        vector<int> dis(n,INT_MAX);
        vector<int> a;
      
        if(adj[k-1].size()==0)
            return -1;
        a = djikstra(adj,k-1,visited,dis);
        for(auto i :a)
            cout<<i<<" ";
        int c = *max_element(a.begin(), a.end());
    
        if(c>=1e7)return -1;
        return c;
    }
};