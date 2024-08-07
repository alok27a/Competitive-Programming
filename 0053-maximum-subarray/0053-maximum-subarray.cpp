class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], maxTillNow = nums[0];
        int n = nums.size();
        
        for(int i=1;i<n;i++)
        {
            maxTillNow = max(maxTillNow + nums[i],nums[i]);
            res = max(res,maxTillNow); 
        }
        return res; 
    }
};