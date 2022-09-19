class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        if(s.size()!=nums.size())
            return true;
        return false;
    }
};