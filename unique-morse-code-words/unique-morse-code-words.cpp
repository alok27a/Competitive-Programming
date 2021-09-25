class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string a[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> output;
        int i,j,l,n=words.size();
        string str;
        for(i=0;i<n;i++)
        {
            str="";
            l=words[i].size();
            for(j=0;j<l;j++)
            {
                str+=a[words[i][j]-97];
            }
            output.insert(str);
            cout<<str<<endl;
        }
        return output.size(); 
    }
};