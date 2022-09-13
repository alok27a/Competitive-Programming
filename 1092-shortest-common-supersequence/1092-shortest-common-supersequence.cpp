class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
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
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        int i = n, j = m;
        string op="";
        
//         Same as printing lcs without line 51 & 56
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                op.push_back(s1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(t[i-1][j]>t[i][j-1])
                {
                    op.push_back(s1[i-1]);
                    i--;
                }
                else
                {
                    op.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        
        while(i>0)
        {
            op.push_back(s1[i-1]);
            i--;
        }
        while(j>0)
        {
            op.push_back(s2[j-1]);
            j--;
        }
        reverse(op.begin(),op.end());
        return op;
    }
};