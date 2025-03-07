class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};
        vector<vector<int>> ans;
        if(numRows == 2)
            return {{1},{1,1}};
        vector<int> pr = {1,1};
        ans.push_back({1});
        ans.push_back({1,1});
        while(numRows-2!=0)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<pr.size()-1;i++)
            {
                temp.push_back(pr[i] + pr[i+1]);
            }
            temp.push_back(1);
            pr = temp;
            ans.push_back(temp);
            numRows--;
        } 
        return ans;
    }
};