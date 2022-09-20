class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
        {
            return 0;
        }
        else if(n==1 || n==2)
        {
            return 1;
        }
        else
        {
            int t[n+2] ;
            t[0] = 0;
            t[1] = 1;
            t[2] = 1;
            
            for(int i=3;i<=n;i++)
            {
                t[i] = t[i-3] + t[i-2] + t[i-1];
            }
            return t[n];
        }
    }
};