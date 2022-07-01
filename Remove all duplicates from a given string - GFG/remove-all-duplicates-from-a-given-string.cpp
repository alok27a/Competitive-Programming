// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
string removeDuplicates(string str) {
    // code here
    
    int cnt[150]={};
    string ans="";
    
    for(int i=0;i<str.size();i++){
        if(cnt[str[i]]==0)
        ans+=str[i];
        
       cnt[str[i]]++;
    }
    return ans;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends