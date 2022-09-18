class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // cout<<i<<j<<endl;
                if(i!=j && arr[i]==2*arr[j])
                {
                    // cout<<arr[i]<<" " << arr[j]<<endl;
                    cout<<i<<" "<<j;
                    return true;
                }
            }
        }
        return false;
    }
};