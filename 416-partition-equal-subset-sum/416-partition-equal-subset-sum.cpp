class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int N = arr.size();
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2!=0)
        {
            return false;
        }
        
        // So we need to find if there exist a subset with sum as sum/2 
        // Applying subset sum problem 
        int W =sum/2;
        bool t[N+1][W+1];
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(i==0)
                {
                    t[i][j] = false;
                }
                if(j==0)
                {
                    t[i][j] = true;
                }
            }
        }
        
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
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