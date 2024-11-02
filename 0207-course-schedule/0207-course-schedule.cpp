class Solution {
public:
    
    bool dfs(vector<bool>& visited, vector<bool>& inRecStack, vector<int> adj[], int node) {
        visited[node] = true;
        inRecStack[node] = true;
        
        for (auto v : adj[node]) {
            if (!visited[v]) {
                if (dfs(visited, inRecStack, adj, v)) 
                    return true; // Cycle found
            } else if (inRecStack[v]) {
                return true; // Cycle found
            }
        }
        
        inRecStack[node] = false; // Remove the node from recursion stack
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        // Create adjacency list
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> inRecStack(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(visited, inRecStack, adj, i)) 
                    return false; // Cycle found
            }
        }
        
        return true; // No cycle detected
    }
};
