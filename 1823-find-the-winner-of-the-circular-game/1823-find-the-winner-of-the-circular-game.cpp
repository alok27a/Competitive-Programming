class Solution {
public:
    int findTheWinner(int n, int k) {
         return win(n,k)+1;
             
    }
    
    int win(int n,int k)
    {
        if(n==1)
            return 0;
        else
            return (win(n-1, k)+k)%n;  
    }
};