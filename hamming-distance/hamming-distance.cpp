class Solution {
public:
    int hammingDistance(int x, int y) {
        int r,count=0,a;
        a=x^y;
        while(a>0){
            r=a%2;
            a=a/2;
            if(r==1)
                count++;
        }
        return count;;
    }
};