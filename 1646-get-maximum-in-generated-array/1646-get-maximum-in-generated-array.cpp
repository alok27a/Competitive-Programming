class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)
        {
            return n; 
        }
        else
        {
            int t[n+1];
            t[0] = 0;
            t[1] = 1;
            
            for(int i=2;i<=n;i++)
            {
                if(i%2==0)
                {
                    t[i] = t[i/2];
                }
                else
                {
                    t[i] = t[i/2] + t[i/2+1];
                }
            }
            
            return *max_element(t,t+n+1);
        }
    }
};