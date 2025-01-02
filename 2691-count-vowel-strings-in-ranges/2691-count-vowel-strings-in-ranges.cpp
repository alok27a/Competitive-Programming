class Solution {
public:

    bool checkString(char a,char b)
    {
        if((a=='a' || a=='e' || a=='i' || a=='o' || a=='u') && (b=='a' || b=='e' || b=='i' || b=='o' || b=='u')) return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> psum;
        if(checkString(words[0].at(0) , words[0].at(words[0].size()-1)))
            psum.push_back(1);
        else
            psum.push_back(0);

        for(int i=1;i<words.size();i++)
        {
            if(checkString(words[i].at(0) , words[i].at(words[i].size()-1)))
                psum.push_back(psum[i-1] + 1);
            else 
                psum.push_back(psum[i-1]); 
        }

        // Process queries
        for (const auto &query : queries) {
            int l = query[0], r = query[1];
            if (l == 0) {
                res.push_back(psum[r]);
            } else {
                res.push_back(psum[r] - psum[l - 1]);
            }
        }

        return res;
    }
};