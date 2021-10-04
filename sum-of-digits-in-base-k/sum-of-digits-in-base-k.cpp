class Solution {
public:
    int sumBase(int n, int k) {
        int i,j;
        vector<int> digit_of_k;
        int sum=0;
        while(n>0)
        {
            // digit_of_k.push_back(n%k);
            // cout<<n%k<<endl;
            sum+=n%k;
            n=n/k;
        }
        return sum;
    }
};