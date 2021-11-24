class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i,j,index,flag=0,n=word.size();
        string rev;
        for(i=0;i<n;i++)
        {
            if(word[i]==ch)
            {
                flag=1;
                index=i;
                break;
            }
        }
        if(flag==0)
            return word;
        reverse(word.begin(), word.begin()+index+1);
        return word;
    }
};