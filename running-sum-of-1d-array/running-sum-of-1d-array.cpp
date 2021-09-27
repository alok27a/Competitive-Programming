class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> output;
        int sum,i,j,n=nums.size();
        
        output.push_back(nums[0]);
        for(i=0;i<n;i++)
        {
            sum=nums[i];
            for(j=i+1;j<n;j++)
            {
                sum+=nums[j];
                if(output.size()!=n)
                    output.push_back(sum);
            }
        }
        return output;
    }
};