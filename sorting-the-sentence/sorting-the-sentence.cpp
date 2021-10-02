class Solution {
public:
       string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string> w;
        while(ss >> word){
            w.push_back(word);
        }
        
        sort(w.begin(),w.end(),
             [&](string a,string b){
                 return a[a.size()-1] < b[b.size()-1];
             }
            );
        string ans="";
        for(auto x: w)ans+=x.substr(0,x.size()-1)+" ";
        
        return ans.substr(0,ans.size()-1);
        
    }
};