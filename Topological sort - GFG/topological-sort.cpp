// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void BFS(int V,vector<int> adj[], vector<int> &indegree,vector<int> &res)
	{
	    queue<int> q;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        res.push_back(u);
	       // cout<<u<<" ";
	        
	        for(auto v : adj[u])
	        {
	            indegree[v]--;
	            if(indegree[v]==0)
	                q.push(v);
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto v: adj[i])
	        {
	            indegree[v]++;
	        }
	    }
        vector<int> res;
        BFS(V,adj,indegree,res);
    	return res;   
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends