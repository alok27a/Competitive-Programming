class Solution {
public:
bool isbipart(int start, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = !color[node];
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> adj[v];

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < graph[i].size(); j++){
            adj[i].push_back(graph[i][j]);
        }
    }

    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (isbipart(i, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

};