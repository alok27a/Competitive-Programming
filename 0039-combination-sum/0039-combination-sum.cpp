class Solution {
public:
    void func(vector<int>& candidates, int target,int ind,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }

        // Picking up an element 
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            func(candidates,target-candidates[ind],ind,ds,ans);
            ds.pop_back();
        }

        // Not-picking up an element 
        func(candidates,target,ind+1,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(candidates,target,0,ds,ans);
        return ans;
    }
};