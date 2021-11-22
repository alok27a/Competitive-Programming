class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
vector s={0,1,3,6,10,15,21,28};
       if(n<7) { return s[n]; }
    
    int N=n/7; // N= numsber of terms
    
    
    
    ans = (56+(N-1)*7)*N/2 + N*(n%7) + s[n%7]; //analyze and get sum formula
    
    return ans;
    }
};