class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i,n=nums.size();
        sort(nums.begin(),nums.end());
        for(i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};