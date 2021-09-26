class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd,even,output;
        int i,j,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        for(i=0;i<even.size();i++)
        {
            output.push_back(even[i]);
        }
        for(i=0;i<odd.size();i++)
        {
            output.push_back(odd[i]);
        }
        return output;
    }
};