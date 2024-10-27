class Solution {
public:
//     If u get a cycle then return false else true
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        queue<int> q;
        
        vector<int> adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]] ++;
        }
        
        for(int i=0;i<indeg.size();i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(int i: adj[curr])
            {
                indeg[i] --;
                if(indeg[i] == 0)
                {
                    q.push(i);
                }
            }
            count++;
        }
        
        return (count == numCourses);
    }
};