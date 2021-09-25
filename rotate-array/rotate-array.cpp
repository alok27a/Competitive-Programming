class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    long int i,j,n=nums.size();
    k = k % n;
     std::rotate(nums.begin(), nums.begin() + (n - k), nums.end());}
};