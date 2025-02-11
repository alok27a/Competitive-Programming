class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1)
            return {{1}};
        else if(numRows == 2)
            return {{1},{1,1}};
        else
        {
            vector<vector<int>> res;
            res.push_back({1});
            res.push_back({1,1});
            vector<int> prev = {1,1};
            vector<int> curr;
            while(numRows-2!=0)
            {
                curr.push_back(1);
                for(int i=0;i<prev.size()-1;i++)
                {
                    curr.push_back(prev[i] + prev[i+1]);
                }
                curr.push_back(1);
                res.push_back(curr);
                prev = curr;
                curr={};
                numRows--;
            }
            return res;
        }
    }
};