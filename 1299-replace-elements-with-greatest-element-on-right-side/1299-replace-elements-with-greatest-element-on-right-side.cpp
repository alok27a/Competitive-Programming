class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxTillNow = arr[n-1];
        
        vector<int> ans;
        ans.push_back(-1);
        for(int i=n-2;i>=0;i--)
        {
             ans.push_back(maxTillNow);
            if(arr[i]>maxTillNow)
            {
               
                maxTillNow = arr[i];
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};