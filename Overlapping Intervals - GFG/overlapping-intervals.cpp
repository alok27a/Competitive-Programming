// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
        stack<vector<int>> st;
        st.push(intervals[0]);
        
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=st.top().at(1))
            {
//                 Overlap
                vector<int> v;
                v.push_back(st.top().at(0));
                if(intervals[i][1]>st.top().at(1))
                    v.push_back(intervals[i][1]);
                else
                    v.push_back(st.top().at(1));
                st.pop();
                st.push(v);
            }
            else
            {
//                 Not overlap
                st.push(intervals[i]);
            }
        }
        vector<vector<int>> out;
        
        while(!st.empty())
        {
            vector<int> v = st.top();
            st.pop();
            out.push_back(v);
        }
        sort(out.begin(),out.end());
        return out;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends