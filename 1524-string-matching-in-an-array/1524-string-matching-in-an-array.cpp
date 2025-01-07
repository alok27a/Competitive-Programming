class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            string s = words[i];
            int flag = 0;

            for(int j=0;j<n; j++)
            {
                if(j!=i && words[j].find(s) !=  std::string::npos)
                {
                   flag = 1;
                }
            }
            if(flag==1)
                result.push_back(s);
        }

        return result;
    }
};