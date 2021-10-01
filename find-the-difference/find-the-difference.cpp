class Solution {
public:
    char findTheDifference(string s, string t) {
        int i,j,n=s.size(),m=t.size();
        vector<char> s1,s2,r;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(n==0)
            return t[0];
        
        for(i=0;i<n;i++)
        {
            s1.push_back(s[i]);
        }
        for(i=0;i<m;i++)
        {
            s2.push_back(t[i]);
        }
        
    set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),inserter(r,r.end()));
            vector<char> result(r.begin(),r.end());
            return result.front();
    }
};