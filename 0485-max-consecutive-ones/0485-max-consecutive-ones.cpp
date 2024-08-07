class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int result = 0; 
        int n = nums.size();
        int maxTillNow = 0;
           
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                maxTillNow++;
                result = max(maxTillNow,result);
            }
            else
            {
                maxTillNow = 0;
            }
        }
        return result;
    }
};