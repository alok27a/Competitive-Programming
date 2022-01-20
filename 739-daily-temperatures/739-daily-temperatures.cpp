class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> op;
        op=nextGreater(temperatures,temperatures.size());
        return op;
    }
    
    vector<int> nextGreater(vector<int> v,int n)
{
    int i;
    stack<int> s;
    vector<int> output;

    s.push(n-1);
    output.push_back(0);

    for (i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false && v[s.top()]<=v[i])
            s.pop();
        int mg = s.empty() ? 0 : s.top()-i;
        output.push_back(mg);
        s.push(i);
    }
    reverse(output.begin(), output.end());
    return output;
}

};