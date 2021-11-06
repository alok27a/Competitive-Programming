class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i,j,flag=0,temp=n;
        vector<int> output;
        if(n==1)
            return true;
        while(n>0)
        {
            output.push_back(n%2);
            n=n/2;
        }
        for(i=0;i<output.size()-1;i++)
        {
            if(output[i]!=output[i+1])
                flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            return true;
        return false;
    }
};