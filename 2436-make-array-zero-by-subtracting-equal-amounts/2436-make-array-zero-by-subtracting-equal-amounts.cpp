class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        unordered_map<int,bool> unique;
        int ans = 0;
        for(int n : nums){
            if(n > 0 && !unique[n]){
                unique[n] = true;
                ans++;
            }
        }
        return ans;
    }
};