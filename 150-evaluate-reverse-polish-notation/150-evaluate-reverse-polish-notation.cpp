class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i,j,n=tokens.size();
        stack<int> st;
        
        for(i=0;i<n;i++)
        {
            if(tokens[i]=="+")
            {
                int e1=st.top();
                st.pop();
                int e2=st.top();
                st.pop();
                cout<<e1+e2<<endl;
                st.push(e1+e2);
            }
            else if(tokens[i]=="-")
            {
                int e1=st.top();
                st.pop();
                int e2=st.top();
                st.pop();
                st.push(e2-e1);
            }
            else if(tokens[i]=="*")
            {
                int e1=st.top();
                st.pop();
                int e2=st.top();
                st.pop();
                st.push(e1*e2);
            }
            else if(tokens[i]=="/")
            {
                int e1=st.top();
                st.pop();
                int e2=st.top();
                st.pop();
                cout<<e1<<" "<<e2<<endl;
                cout<<e2/e1<<endl;
                st.push(e2/e1);
            }
            else
            {
                int t=stoi(tokens[i]);
                st.push(t);
            }
        }
        
        return st.top();
    }
};