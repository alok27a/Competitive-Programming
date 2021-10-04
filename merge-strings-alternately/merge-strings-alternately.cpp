class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,j,m=word1.size(),n=word2.size();
        vector<char> c;
        if(m==n)
        {
            for(i=0;i<m;i++)
            {
                c.push_back(word1[i]);
                c.push_back(word2[i]);
            }
            return std::accumulate(c.begin(), c.end(), std::string(""));
        }
        else if(m>n)
        {
            for(i=0;i<n;i++)
            {
                c.push_back(word1[i]);
                c.push_back(word2[i]);
            }
    
            for(i=n;i<m;i++)
            {
                 c.push_back(word1[i]);
            }
            return  std::accumulate(c.begin(), c.end(), std::string(""));
        }
        else{
            for(i=0;i<m;i++)
            {
                c.push_back(word1[i]);
                c.push_back(word2[i]);
            }
    
            for(i=m;i<n;i++)
            {
                 c.push_back(word2[i]);
            }
            return  std::accumulate(c.begin(), c.end(), std::string(""));
        }
        
    }
};