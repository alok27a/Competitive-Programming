class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int maxTillNow = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans = max(ans,maxTillNow);
                maxTillNow = 0;
            }
            else
            {
                maxTillNow++;
            }
        }
        
        ans = max(ans,maxTillNow);
        
        return ans;
    }
};