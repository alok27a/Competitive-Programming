// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int,vector<int>,greater<int>> pq;
        
        // We are keeping only k elements in the min heap
        for(int i=0;i<=k;i++)
        {
            pq.push(arr[i]);
        }
        int index=0;
        for(int i=k+1;i<n;i++)
        {
            int a = pq.top();
            pq.pop();
            arr[index++] = a;
            pq.push(arr[i]);
        }
        while(!pq.empty())
        {
            arr[index++] = pq.top();
            pq.pop();
        }
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(arr[i]);
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends