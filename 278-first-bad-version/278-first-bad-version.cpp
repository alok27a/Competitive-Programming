// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long long m , s = 1 , e = n;
        m = (s+e)/2;
        while(s<=e)
        {
            if(isBadVersion(m))
            {
                e = m - 1; 
            }
            else if(!isBadVersion(m))
            {
                s = m + 1;
            }
            m = (s+e)/2; 
        }
        return m + 1 ;
    }
};