class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int i,j,n=nums.size();
        vector<int> o;
        for(i=0;i<n;i++)
        {
            o.push_back(nums[i]);
        }
        for(i=0;i<n;i++)
        {
            o.push_back(nums[i]);
        }
        return o;
    }
};