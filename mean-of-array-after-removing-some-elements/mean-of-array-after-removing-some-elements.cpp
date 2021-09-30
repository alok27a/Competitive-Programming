class Solution {
public:
    double trimMean(vector<int>& arr) {
        int i,j,n=arr.size();
        double sum=0,remove=(0.05)*n;
        
        vector<int> output;
        sort(arr.begin(),arr.end());
        for(i=remove;i<n-remove;i++)
        {
            output.push_back(arr[i]);
            sum+=arr[i];
        }
        return sum/output.size();
    }
};