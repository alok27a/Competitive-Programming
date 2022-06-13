// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/
#include <algorithm>

class Solution {
public:
    int PalinArray(int a[], int n)
    {
        for(int i=0;i<n;i++)
        {
            int t = palindromeCheck(a[i]);
            if(t==0)
                return 0;
        }
        return 1;
    }
    
    int palindromeCheck(int n)
    {
        string s = to_string(n);
        string t = s;
        reverse(t.begin(),t.end());
        if(s==t)
        {
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends