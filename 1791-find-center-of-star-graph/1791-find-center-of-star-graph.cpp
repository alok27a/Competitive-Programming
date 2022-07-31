class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n+1,0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            degree[u]++;
            degree[v]++;
        }
        
        for(int i=0;i<degree.size();i++)
        {
            if(degree[i] == edges.size())
                return i+1;
        }
        return -1;
    }
};