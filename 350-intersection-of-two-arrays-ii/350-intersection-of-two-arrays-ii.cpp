class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> ans;
        for(int i : nums1) 
            m[i] += 1;
        for(int i : nums2) 
            if(m[i]-- > 0)
                ans.push_back(i); 
        return ans;
    }
};