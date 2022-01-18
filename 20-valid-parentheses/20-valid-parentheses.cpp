class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // initializing an empty stack
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                 st.push(s[i]); // whenever any opening bracket comes we would push the element
            else
            {
                if(st.empty()) return false; // checking whether the stack has any element or not, ie. if a closing bracket comes before opening
				
				// conditions to check whether the given(ques) conditions are true or not
                if(s[i]==')' && st.top()!='(')
                    return false; 
                if(s[i]=='}' && st.top()!='{')
                    return false; 
                if(s[i]==']' && st.top()!='[')
                    return false; 
                st.pop(); // finally popping the opening bracket
            }
        }
        return st.empty(); // if the stack is empty meaning the pattern is found.
    }
};