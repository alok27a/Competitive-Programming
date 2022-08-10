class Solution {
public:
    
    bool dfs( unordered_map<int,list<int>> &mp,vector<bool> &visited, vector<bool> &recst,int node)
    {
        visited[node] = true;
        recst[node] = true;
        
        for(auto v : mp[node])
        {
            if(visited[v]!=true && dfs(mp,visited,recst,v))
            {
                return true;   
            }
            else if(visited[v]==true && recst[v]==true)
            {
                return true;
            }
        }
        recst[node] = false;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> mp;
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            mp[u].push_back(v);
        }
        
        vector<bool> visited(numCourses,false);
        vector<bool> recst(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]!=true)
            {
                if(dfs(mp,visited,recst,i))
                    return false;
            }
        }
        return true;
    }
};