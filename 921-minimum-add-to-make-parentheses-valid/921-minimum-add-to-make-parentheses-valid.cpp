class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n = s.size();
        stack<char> st;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty()==true && s[i]==')')
            {
                count++;
            }
            else if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')') 
            {
                st.pop();
            }
        }
        
        int c = 0;
        while(!st.empty())
        {
            c++;
            st.pop();
        }
        return c+count;
    }
};