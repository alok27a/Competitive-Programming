class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i,j,m=nums1.size(),n=nums2.size();
        vector<int> output;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(nums1[j]==nums2[i])
                {
                    output.push_back(nums1[j]);
                    break;
                }
            }
        }
        set<int> s;
        for(i=0;i<output.size();i++)
        {
            s.insert(output[i]);
        }
        vector<int> o(s.begin(),s.end());
        return o;
    }
};