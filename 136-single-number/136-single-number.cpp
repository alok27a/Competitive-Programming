class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i,j=0;
        if(n==1)
        {
            return nums[0];
        }
        else
        {
            sort(nums.begin(),nums.end());
            for(i=0;i<n;i=(i+2)%(n))
            {
                if(nums[i]!=nums[(i+1)%n])
                {
                    return nums[i];
                }
            }
            return nums[n-1];
        }
    }
};