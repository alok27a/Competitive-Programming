class Solution {
public:
    void solve(vector<string> &ans,string s,int i)
    {
        if(i==s.size())
        {
            ans.push_back(s);
            return;
        }
        if(isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            solve(ans,s,i+1);
            s[i] = tolower(s[i]);
            solve(ans,s,i+1);
        }
        else
        {
            solve(ans,s,i+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(ans,s,0);
        return ans;
    }
};