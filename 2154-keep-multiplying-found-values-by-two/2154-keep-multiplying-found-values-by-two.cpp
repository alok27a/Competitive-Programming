class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size(),i;
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==original)
            {
                original*=2;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            return findFinalValue(nums, original);
        }
        return original;
        
    }
};