class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
           return false;
        
        int count = 0;
        
        while(n)
        {
            if(n & 1)
            {
                count++;
            }
            
            if(count > 1)
                return false;
            
            n = n >> 1;
        }
        
        return true;}
};