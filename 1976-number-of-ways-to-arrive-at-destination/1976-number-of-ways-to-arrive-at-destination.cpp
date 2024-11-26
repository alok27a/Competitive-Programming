class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Creating adjacency list 
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>,
                        vector<pair<long long, int>>,
                        greater<pair<long long, int>>> pq;

        // Use long long to avoid overflow
        vector<long long> dist(n, LLONG_MAX);  // Change to long long
        vector<long long> ways(n, 0);  // Change to long long

        // {dist, node}
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        long long mod = 1e9 + 7;  // Modulo value as long long

        while (!pq.empty()) {
            long long dis = pq.top().first;  // Use long long for dis
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long adjDis = it.second;  // Use long long for adjDis

                // Relaxation condition
                if (dis + adjDis < dist[adjNode]) {
                    dist[adjNode] = dis + adjDis;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                // If a path with the same distance is found, add ways
                else if (dis + adjDis == dist[adjNode]) {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
