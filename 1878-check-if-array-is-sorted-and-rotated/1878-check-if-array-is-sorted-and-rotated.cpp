class Solution {
public:
    bool check(vector<int>& nums) {
        int inversionCount = 0 ;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1]) inversionCount++;
        }

        // Comparing thw last and the first element once. 
        if(nums[0] < nums[n-1]) inversionCount++;

        return inversionCount <= 1;
    }
};