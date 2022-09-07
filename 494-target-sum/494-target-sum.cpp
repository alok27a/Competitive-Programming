class Solution {
public:
//     Same as count of number of subset with given sum
    
//     int countSum(vector<int> arr,int n,int W)
//     {
//         vector<vector<int>> t(n+1,vector<int>(W+1,-1));
//         // for(int i=0;i<=n;i++)
//         // {
//         //     for(int j=0;j<=W;j++)
//         //     {
//         //         if(i==0)
//         //             t[i][j] = 0;
//         //         if(j==0)
//         //             t[i][j] = 1;
//         //         // cout<<t[i][j]<<endl;
//         //     }
//         // }
//         t[0][0] = 1;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=0;j<=W;j++)
//             {
//                 if(arr[i-1]<=j)
//                 {
//                     t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
//                 }
//                 else
//                 {
//                     t[i][j] = t[i-1][j];
//                 }
//             }
//         }
//         return t[n][W];
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++)
//         {
//             sum+=nums[i];
//         }
//         if(target>sum || (sum-target)%2!=0)
//         {
//             return 0;
//         }
//         int diff = (target+sum)/2;
//         int t = countSum(nums,n,diff);
//         return t;
//     }
     int tab(vector<int>& nums, int t, int sum)
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
       return dp[n][sum]; 
    }
    
    int findTargetSumWays(vector<int>& nums, int t) {
        int s=0;
        for(auto it:nums)
        {
            s+=it;
        }
        if(t>s || (s-t)%2!=0)
        {
            return 0;
        }
        return tab(nums,t,(s-t)/2);
    }
};