class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
         int count=0;
        for(char ch :stones){
            if(jewels.find(ch)!=string::npos)
                 count++;
        }
        cout<<count;
        return count;
    }
};