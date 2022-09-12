class Solution {
public:
     vector<int> runningSum(vector<int>& nums) {
        vector<int> output;
        int sum,i,j,n=nums.size();
        
        output.push_back(nums[0]);
        for(i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};