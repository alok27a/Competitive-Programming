class Solution {
public:
    bool isSameAfterReversals(int num) {
            
        int temp=num;
        if(temp==reverse(reverse(num)))
            return true;
        return false;
        
    }
    
    int reverse(int n){
        int remainder,reversedNumber=0;
        while(n != 0) {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
        }
        return reversedNumber;
    }
};