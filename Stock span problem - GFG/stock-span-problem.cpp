// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       int i,j;
       stack<int> st;
       vector<int> out;
       
       st.push(0);
       for(i=0;i<n;i++)
       {
           while(!st.empty() && price[st.top()]<=price[i])
           {
               st.pop();
           }
           int t = st.empty()?i+1:i-st.top();
           out.push_back(t);
           st.push(i);
       }
       return out;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends