class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i,j,n=nums.size();
        vector<int> o;
        for(i=0;i<n;i++)
        {
            o.push_back(nums[nums[i]]);
        }
        return o;
    }
};