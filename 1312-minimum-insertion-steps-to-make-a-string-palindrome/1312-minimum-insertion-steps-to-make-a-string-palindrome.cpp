class Solution {
public:
    int minInsertions(string s) {
    string s1 = s;
    reverse(s.begin(),s.end());
    int n = s.size();
    
    int dp[n+1][n+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
           if(s[i-1]==s1[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
           }else{
               dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
           }
        }
    }
      int ans = n - dp[n][n];
    
    return ans;
    }
};