class Solution {
public:
    vector<int>v;
    int heightChecker(vector<int>& heights) {
       v=heights;
        sort(v.begin(),v.end());
        int c=0;
        for(int i=0;i<heights.size();i++)
        {
            if(v[i]!=heights[i])
                c++;
        }
        return c;
        
    }
};