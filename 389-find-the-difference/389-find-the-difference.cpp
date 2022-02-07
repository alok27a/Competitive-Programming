class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n=s.size();
        
        vector<char> first,second,ls;
        
        for(int i=0;i<n;i++)
        {
            first.push_back(s[i]);
            second.push_back(t[i]);
        }
        second.push_back(t[n]);
         std::set_difference(second.begin(), second.end(),first.begin(), first.end(),
        std::inserter(ls, ls.begin()));
        
        return ls[0];
        
    }
};