class Solution {
public:
    int longestContinuousSubstring(string s) {
         int n = s.size();
        int res = INT_MIN,maxi = 1;
        
        if(n==1)
            return 1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]+1==s[i+1])
            {
                maxi++;
            }
            else
            {
                maxi = 1;
            }
            cout<<maxi;
            res = max(maxi,res);
        }
        return res;
    }
};