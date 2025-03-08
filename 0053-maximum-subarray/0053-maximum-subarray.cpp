class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnd = nums[0];
        int result = nums[0];
        int n = nums.size();

        for(int i=1;i<n;i++)
        {
            maxEnd = max(maxEnd+nums[i],nums[i]);
            result = max(result,maxEnd);
        }
        return result;
    }
};