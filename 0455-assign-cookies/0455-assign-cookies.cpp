class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size();
        int n2 = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int l=0,r=0;

        while(l<n1 && r<n2)
        {
            if(g[l]<=s[r])
            {
                l++;
            }
            r++;
        }
        return l;
    }
};