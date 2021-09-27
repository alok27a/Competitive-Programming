class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> output,zeroes;
        int i,j,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[i]!=0)
                output.push_back(nums[i]);
            else
                zeroes.push_back(nums[i]);
        }
        output.resize(n);
        nums=output;
    }
};