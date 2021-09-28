class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i,j,n=nums.size();
        vector<int> output;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                    output.push_back(nums[j]-nums[i]);
            }
        }
        sort(output.begin(),output.end());
        if(output.size()==0)
            return -1;
        return output[output.size()-1];
    }
};