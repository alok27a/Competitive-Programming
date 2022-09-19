class Solution {
public:
    string getString(char x)
{
    // string class has a constructor
    // that allows us to specify size of
    // string as first parameter and character
    // to be filled in given size as second
    // parameter.
    string s(1, x);
 
    return s;  
}
    
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;
        st.push(getString(s[0]));
        int count;
        
        for(int i=1;i<n;i++)
        {
            string a = getString(s[i]);
            
            if(a=="]")
            {
                string ans;
                string finalans;
                while(st.top()!="["){    
                   ans=st.top()+ans; 
                    st.pop();
                }
                st.pop();
                string temp;

                while(!st.empty() && st.top()>="0" && st.top()<="9"){
                      temp=st.top()+temp;
                    
                        st.pop();
                }

                count=stoi(temp);
                while(count>0){
                    finalans=ans+finalans;
                    count--;
                }
                st.push(finalans);     
            }
            else
            {
                st.push(a);
            }
        }
        string finalans;
        while(!st.empty()){
            finalans=st.top()+finalans;
            st.pop();
        }
        return finalans;
    }
};