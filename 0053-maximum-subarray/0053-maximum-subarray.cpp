class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnd = nums[0], ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxEnd = max(nums[i], nums[i] + maxEnd);
            ans = max(ans,maxEnd);
        }
        return ans;
    }
};