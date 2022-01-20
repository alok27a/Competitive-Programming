class Solution {
public:
    string removeDuplicates(string s) {
        string output="";
        stack<char> st;
        int i,n=s.size();
        st.push(s[0]);
        
        for(i=1;i<n;i++)
        {
            if(!st.empty() && st.top()!=s[i])
                st.push(s[i]);
            else if(!st.empty() && st.top()==s[i] )
            {
                st.pop();
            }
            else 
                st.push(s[i]);
        }
        
        while(!st.empty())
        {
            output+=st.top();
            st.pop();
        }
        reverse(output.begin(),output.end());
        return output;
    }
};