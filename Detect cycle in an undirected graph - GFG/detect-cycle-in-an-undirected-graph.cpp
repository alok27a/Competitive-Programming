// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
   bool BFS(vector<int> adj[],int V,int s,vector<bool> &visited)
    {
        vector<int> parent(V,-1);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for (auto v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
                }else if (parent[u] != v) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
         vector<bool> visited(V, false);
 
        for(int i = 0; i < V; i++)
            if(!visited[i] && BFS(adj,V,i, visited))
                return true;
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends