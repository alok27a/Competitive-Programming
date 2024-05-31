class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int minValue = arr[0] ;
        int result = arr[1] - arr[0];
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            result = max(result, arr[i]-minValue);
            minValue = min(minValue, arr[i]);
        }
        if(result<=0)
            return -1;
        return result;
    }
};