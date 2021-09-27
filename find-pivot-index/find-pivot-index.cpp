class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int sum1=0,sum2=0,i,j,n=v.size(),pivot;
        
        
        for(i=0;i<n;i++)
        {
            pivot=v[i];
            sum1=0;
            sum2=0;
            sum1=accumulate(v.begin(),v.begin()+i,sum1);
            sum2=accumulate(v.begin()+i+1,v.end(),sum2);
            if(sum1==sum2)
                return i;
        }
        return -1;
    }
};