class Solution {
public:

    vector<int> rotatedArray(vector<int> arr, int d)
    {
        int res[arr.size()];
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            res[(i+d)%arr.size()] = arr[i];
        }
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(res[i]);
        }
        return ans;
    }

    bool check(vector<int>& nums) {
        vector<int> cmp = nums;
        int flag = 0;
        sort(cmp.begin(),cmp.end());
        for(int rot=0;rot<nums.size();rot++)
        {
            if(cmp == rotatedArray(nums,rot))
            {
                flag = 1;
                break;
            }
        }

        return (flag==1)?true:false;
    }
};