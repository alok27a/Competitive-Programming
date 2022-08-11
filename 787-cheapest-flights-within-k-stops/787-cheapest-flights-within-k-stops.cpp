#define pb push_back
class Solution {
public:
    
          int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<long long> dist(n,INT_MAX);
	    dist[src] = 0;
	    for(int i = 0;i<=k;i++)
	    {
            vector<long long> temp = dist;
	        for(auto &u: edges)
	        {
	            if(temp[u[1]] > dist[u[0]] + u[2])
	            {
	                temp[u[1]] = dist[u[0]] + u[2];
	            }
	        }
            dist = temp;
	    }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }

};