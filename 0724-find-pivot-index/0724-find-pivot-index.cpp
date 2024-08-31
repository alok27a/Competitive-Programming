class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    // Prefix sum caculate it and suffix sum also calculate it
        int n = nums.size();
        
        //  Prefix sum calculation 
        vector<int> pSum;
        
        pSum.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            pSum.push_back(nums[i] + pSum[i-1]);
        }
        
        //  Suffix sum calculatiom      
        //  It is basically reverse of pSum
        
        vector<int> sSum;
        
        sSum.push_back(pSum[n-1]);
        
        for(int i=1;i<n;i++)
        {
            sSum.push_back(sSum[i-1] - nums[i-1]);
        }
        
        for(int i=0;i<n;i++)
        {
            // cout<<"pSum "<< pSum[i]<< " sSum "<< sSum[i]<<endl;
            if(sSum[i] == pSum[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};