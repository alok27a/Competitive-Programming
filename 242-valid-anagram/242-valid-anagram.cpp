class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> c1,c2;
        int i,j,n=s.size(),m=t.size();
        
        if(n==m)
        {
            for(i=0;i<n;i++)
            {
                c1.push_back(s[i]);
                c2.push_back(t[i]);
            }
            sort(c1.begin(),c1.end());
            sort(c2.begin(),c2.end());
            if(c1==c2)
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
        return false;
    }
};