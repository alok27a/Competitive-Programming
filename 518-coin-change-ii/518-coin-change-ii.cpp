class Solution {
public:
    int change(int sum, vector<int>& arr) {
        int N = arr.size();
        int W = sum;
        int t[N+1][W+1];
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1; 
            }
        }
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j] = t[i-1][j] + t[i][j-arr[i-1]];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[N][W];
    }
};