class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int i,j,n=nums.size();
        sort(nums.begin(),nums.end());
        return (nums[n-1]*nums[n-2])-(nums[1]*nums[0]);
    }
};