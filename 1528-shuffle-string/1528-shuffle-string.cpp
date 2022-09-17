class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=indices.size();
        vector<string> v(n);
        
        for(int i=0;i<indices.size();i++){
            v[indices[i]].push_back(s[i]);
        }
        
        string str;
        for(auto it:v){
            str+=it;
        }
        return str;
    }
};