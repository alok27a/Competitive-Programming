class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Finding the breakpoint 
        int ind = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind = i;
                break;
            }
        }
        // if ind = -1 then the array is reverse sorted 
        if(ind == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        // Now swap the A[ind] with least possible value
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }            
        }

        reverse(nums.begin()+ind+1, nums.end());
    
    }
};