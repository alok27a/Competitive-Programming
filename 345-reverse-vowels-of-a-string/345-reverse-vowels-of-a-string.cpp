class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        vector<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        
        while(i<j)
        {
            if(find(v.begin(),v.end(),s[i])!=v.end()  && find(v.begin(),v.end(),s[j])!=v.end())
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(find(v.begin(),v.end(),s[i])!=v.end() && find(v.begin(),v.end(),s[j])==v.end() )
            {
//                 got in i but not in j
                j--;
            }
            else if(find(v.begin(),v.end(),s[i])==v.end()  && find(v.begin(),v.end(),s[j])!=v.end())
            {
//                 got j but not i
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        
        return s;
    }
};