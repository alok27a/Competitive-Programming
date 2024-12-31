class Solution {
public:

    int dp[367];
    int solve(vector<int>& days, int n, int ind,vector<int>& costs)
    {
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
      
        // Taking 1 day pass 
        int one = costs[0] + solve(days,n,ind+1,costs);
        
        // Taking 7 day pass
        int i = ind;
        while(i<n && days[i] < days[ind] + 7){
            i++;
        }
        int seven = costs[1] + solve(days,n,i,costs);
        
        // Taking 30 day pass
        int j = ind;
        while(j<n && days[j] < days[ind] + 30){
            j++;
        }
        int thirty = costs[2] + solve(days,n,j,costs);

        return dp[ind] = min(one,min(seven,thirty));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,days.size(),0,costs);
    }
};