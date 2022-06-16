// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    
int evaluatePostfix(string postfix)
{
    int i, n = postfix.size();
    stack<int> st;

    for (i = 0; i < n; i++)
    {
        char c = postfix[i];

        if ((c >= '0' && c <= '9'))
        {
            int num = c - '0';
            st.push(num);
        }
        else if (c == '*')
        {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1 * t2);
        }
        else if (c == '+')
        {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1 + t2);
        }
        else if (c == '/')
        {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1 / t2);
        }
        else if (c == '-')
        {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            st.push(t1 - t2);
        }
    }
    return st.top();
}
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends