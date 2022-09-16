class Solution {
public:
    
    int squareSum(int n)
    {
        int sum = 0; 
        while(n>0)
        {
            int d = n%10;
            sum+=(d*d);
            n = n/10;
        }
        return sum;
    }
    
    int numOfDigit(int n)
    {
        int sum = 0;
        int c = 0;
        while(n>0)
        {
            int d = n%10;
            c++;
            sum+=d;
            n=n/10;
        }
        return c;
    }
    
    bool isHappy(int n) {
        
        int temp = n;
        
        if(n==1 || n==7 || n==1111111)
        {
            return true;
        }
        while(numOfDigit(n)!=1)
        {
            n = squareSum(n);
        }
        if(n==1)
        {
            return true;
        }
        return false;
    }
};