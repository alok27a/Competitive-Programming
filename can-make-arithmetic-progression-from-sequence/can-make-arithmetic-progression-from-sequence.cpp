class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int d,i,j,n=arr.size();
        vector<int> output;
        sort(arr.begin(),arr.end());
        
        if(n==2)
            return true;
        
        for(i=0;i<n-1;i++)
        {
            output.push_back(arr[i+1]-arr[i]);    
        }
        int flag=0;
        for(i=0;i<output.size()-1;i++)
        {
            if(output[i]==output[i+1])
                flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            return true;
        else
            return false;
    }
};