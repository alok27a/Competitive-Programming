class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(auto i : nums)
        {
            res = res ^ i;
        }
        return res;
    }
};