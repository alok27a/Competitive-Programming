// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        int i,j;
        int test;
        
        for(i=0;i<n;i++)
        {
            test = X - A[i] ;
            unordered_set<int> s;
            for(j=i+1;j<n;j++)
            {
                if(s.find(test-A[j])!=s.end() && (A[i]+A[j]+test-A[j]==X))
                {
                    return true;
                }
                s.insert(A[j]);
            }
        }
        
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends