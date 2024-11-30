class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>, 
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> pq;
    
        for(int i=0;i<intervals.size();i++)
        {
            pq.push({intervals[i][0],intervals[i][1]});
        }
        
        int s = pq.top().first;
        int e = pq.top().second;
        pq.pop();
        vector<pair<int,int>> res;
        
        while(!pq.empty())
        {
            auto i = pq.top();
            int cs = i.first;
            int ce = i.second;
            pq.pop();
            
            if(e>=cs)
            {
                e = max(e,ce);
            }
            else
            {
                res.push_back({s,e});
                s = cs;
                e = ce;
            }            
        }
        res.push_back({s,e});
        vector<vector<int>> ans;
        
        for(auto i : res)
        {
            int a = i.first;
            int b = i.second;
            ans.push_back({a,b});
        }
        return ans;
    }
};