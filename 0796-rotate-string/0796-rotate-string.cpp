class Solution {
public:
    
    string shiftByOne(string s)
    {
        string ans="";
        int n = s.size();
        ans+=s[n-1];
        
        for(int i=0;i<n-1;i++)
        {
            ans+=s[i];
        }
        return ans;
    }
    
    bool rotateString(string s, string goal) {
        
        int n = s.size();
        string temp = s;
        while(n!=0)
        {
            temp = shiftByOne(temp);
            cout<<temp<<endl;
            if(temp==goal)
                return true;
            n--;
        }
        return false;
    }
};