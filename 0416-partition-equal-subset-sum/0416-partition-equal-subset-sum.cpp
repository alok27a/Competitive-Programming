class Solution {
public:
    int memo[201][10001];
    
    bool dp(vector<int>& nums, int i, int l, int val) {
        if (i >= l) return val == 0;
        if (val < 0) return false;
        if (memo[i][val] != -1) return memo[i][val];
        bool res = dp(nums, i + 1, l, val - nums[i]);
        res = res || dp(nums, i + 1, l, val);
        memo[i][val] = res;
        return memo[i][val];
    }
    
    bool canPartition(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        return dp(nums, 0, nums.size(), sum >> 1);
    }
};