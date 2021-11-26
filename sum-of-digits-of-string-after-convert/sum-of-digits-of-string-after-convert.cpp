class Solution {
public:
    int getLucky(string s, int k) {
         int sum=s.size();
        for(auto i:s) {
            sum+=i-'a';
            if(i>'i') sum-=9;
            if(i>'s') sum-=9;
        }
        while(--k) {
            int tmp=0;
            while(sum) {
                tmp+=sum%10;
                sum/=10;
            }
            sum=tmp;
        }
        return sum;
    }
};