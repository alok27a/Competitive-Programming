class Solution {
public:
     
    void BFS(vector<vector<int>> adj, int V,int s,bool visited[])
    {
        queue<int> q;
        q.push(s);
        visited[s-1] = true;
        
        while(!q.empty())
        {
            int a  = q.front();
            q.pop();
            // cout<<a<<" ";
            
            for(int i=0;i<V;i++)
            {
                if(adj[a-1][i]==1 && visited[i]==false)
                {
                    visited[i] = true;
                    q.push(i+1);
                }
            }
            // cout<<endl;
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V=adj.size();
        int count=0;
        bool visited[V];
        
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
        }
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                BFS(adj,V,i+1,visited);
                count++;
            }
        }
        return count;
    }
};