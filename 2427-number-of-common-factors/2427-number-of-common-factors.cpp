class Solution {
public:
    int commonFactors(int a, int b) {
        vector<int> s1;
        vector<int> s2;
        
        for(int i=1;i<=a;i++)
        {
            if(a%i==0)
                s1.push_back(i);
        }
        
        for(int i=1;i<=b;i++)
        {
            if(b%i==0)
                s2.push_back(i);
        }
        
        vector<int> v1(s1.size()+s2.size());
        std::set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end() ,v1.begin());
        int c =0;
        for(auto i : v1)
        {
            if(i==0)
                break;
            c++;
        }
        
        return c;
    }
};