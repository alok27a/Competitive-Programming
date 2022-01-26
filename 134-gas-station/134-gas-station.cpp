class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j,n=gas.size();
        int start,curr_pet=0,prev_pet=0;
        
        for(i=0;i<n;i++)
        {
            curr_pet+=(gas[i]-cost[i]);
            if(curr_pet<0)
            {
                start=(i+1)%n;
                cout<<start<<endl;
                prev_pet+=curr_pet;
                curr_pet=0;
            }
        }
        
        return (prev_pet+curr_pet>=0)?start:-1;
    }
};