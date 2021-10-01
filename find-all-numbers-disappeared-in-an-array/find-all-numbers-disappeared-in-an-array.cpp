class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i,j=0,n=nums.size();
        sort(nums.begin(),nums.end()); 
        set<int> s1,s2,result;
        
        for(i=0;i<n;i++)
        {
            s1.insert(nums[i]);
            s2.insert(i+1);
        }    
        set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),inserter(result,result.end()));
        vector<int> output(result.begin(),result.end());
        return output;
    }
};