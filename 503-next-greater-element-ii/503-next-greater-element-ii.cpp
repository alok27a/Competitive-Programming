class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
    int i,n=v.size();
    stack<int> s;
    vector<int> output;

    s.push(v[n - 1]);

    for (i = 2*n - 1; i >= 0; --i)
    {
        while (s.empty() == false && s.top()<=v[i%n])
            s.pop();
        int mg = s.empty() ? -1 : s.top();
        output.push_back(mg);
        s.push(v[i%n]);
    }
    reverse(output.begin(), output.end());
       vector<int> o;
        for(i=0;i<n;i++)
            o.push_back(output[i]);
    return o;
    }
};