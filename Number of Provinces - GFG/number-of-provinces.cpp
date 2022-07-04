// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

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
    
    
  
    int numProvinces(vector<vector<int>> adj, int V) {
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

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends