class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0,i,j,n=operations.size();
        
        for(i=0;i<n;i++)
        {
            if(operations[i]=="--X" || operations[i]=="X--")
                x=x-1;
            else if(operations[i]=="++X" || operations[i]=="X++")
                x=x+1;
        }
        return x;
    }
};