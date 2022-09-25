class Solution {
public:
    static bool cmp(pair<string, int>& a,
         pair<string, int>& b)
    {
        return a.second > b.second;
    }
  
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int> > A;
        int n = names.size();
        
        for(int i=0;i<n;i++)
        {
            A.push_back(make_pair(names[i],heights[i]));
        }

        sort(A.begin(), A.end(), cmp);
        
        vector<string> op;
         for (auto& it : A) {
            op.push_back(it.first);
        }
        return op;
    }
};