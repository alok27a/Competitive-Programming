class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i,j,n=nums.size(),count=0;
        vector<int> output;

        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                if(nums[j]<nums[i])
                    count++;
            }
            output.push_back(count);
        }
        return output;
    }
};