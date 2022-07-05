// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
 bool cycle(int node,vector<bool> &vis,vector<bool> &dfsvis,vector<int> adj[]){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(cycle(it,vis,dfsvis,adj)) return true;
            }else if(dfsvis[it]==1) return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool> vis(v,0);
        vector<bool> dfsvis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(cycle(i,vis,dfsvis,adj)) return true;
            }
        }
        return false;
    }

   
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends