class Solution {
public:
    int lengthOfLIS(vector<int>& nums1) {
        vector<int> b;
        set<int> s;
        int n = nums1.size();

        // setting iterator for set
        set<int>::iterator it;

        // storing unique elements
        for (int i = 0; i < n; i++) {
            s.insert(nums1[i]);
        }

        // creating sorted vector
        for (it = s.begin(); it != s.end(); it++) {
            b.push_back(*it);
        }
        
        
        vector<int> nums2 = nums1;
        reverse(nums2.begin(),nums2.end());
        
        int m = b.size();
        
        int t[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    t[i][j] = 0;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]==b[j-1])
                {
                    t[i][j] = t[i-1][j-1]+1; 
                }
                else
                {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }            
        }
        return t[n][m];  
    }
};