class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int i,j,n=nums.size();
        sort(nums.begin(),nums.end());
        return nums;
    }
};