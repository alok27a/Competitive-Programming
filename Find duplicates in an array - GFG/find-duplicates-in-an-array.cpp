// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> op;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto i : mp)
        {
            if(i.second>1)
                op.push_back(i.first);
        }
        if(op.empty())
            return {-1};
        sort(op.begin(),op.end());
        return op;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends