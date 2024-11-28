class Solution {
public:
    void nextPermutation(vector<int>& array) {
        // next_permutation(array.begin(), array.end());
        int ind = -1;
        int n = array.size();
        
//         Finding the breakpoint
        for(int i=n-2;i>=0;i--)
        {
            if(array[i] < array[i+1])
            {
                ind = i;
                break;
            }
        }
        if(ind==-1)
        {
            reverse(array.begin(),array.end());
            return;
        }
        
//      Swapping ind with the minimum of the remaining
        
        for(int i=n-1;i>ind;i--)
        {
            if(array[i]>array[ind])
            {
                swap(array[i],array[ind]);
                break;
            }
        }
        
        reverse(array.begin()+ind+1,array.end());
    }
};