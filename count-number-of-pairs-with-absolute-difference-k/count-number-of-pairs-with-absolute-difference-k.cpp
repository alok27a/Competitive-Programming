class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i,j,n=nums.size(),count=0;
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(abs(nums[j]-nums[i])==k)
                    count++;
            }
        }
        return count;
    }
};