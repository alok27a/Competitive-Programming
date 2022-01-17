class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string res = "";
        int i = 0, k = 0;
        
        while (i < s.size() && k < spaces.size())
        {
            if (spaces[k] == i)
            {
                k++;
                res += " ";
            }
            res += s[i++];
        }
        
        while (i < s.size())
            res += s[i++];
        
        return res;
    }
};