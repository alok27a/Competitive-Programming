class Solution {
public:
    int minDistance(string s1, string s2) {
//         Finding LCS 
        int n = s1.size(),m = s2.size();
        int t[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        int l = t[n][m];
        int ans = 0;
        ans = (n-l) + (m-l);
        return ans;
    }
};