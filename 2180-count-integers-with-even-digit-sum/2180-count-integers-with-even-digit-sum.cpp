class Solution {
public:
    int countEven(int num) {
            
        int i,j,c=0;
        for(i=1;i<=num;i++)
        {
            if(digitSum(i)%2==0)
                c++;
        }
        return c;
    }
    
    int digitSum(int a)
    {
        int temp=a;
        int sum=0;
        while(a!=0)
        {
            sum+=a%10;
            a=a/10;
        }
        return sum;
    }
    
};