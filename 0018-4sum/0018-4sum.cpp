class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue; // Skip duplicates for i
            for(int j=i+1;j<n;j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue; // Fix: Skip duplicates for j
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum>target)
                    {
                        l--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};
