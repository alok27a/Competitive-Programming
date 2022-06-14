// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool checkCorres(char c1, char c2)
{
    if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    else if (c1 == '{' && c2 == '}')
        return true;
    else
        return false;
}

bool ispar(string str)
{
    int i, j;
    stack<char> st;
    if(str.size()==1)
        return false;

    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if(st.empty())
                return false;
            if (checkCorres(st.top(), str[i]) == 0)
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.empty())
        return true;
    return false;
}

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends