class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n=a.size();
        int maxe = *max_element(a.begin(),a.end());
        
        int c=0;
        int maxc=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==maxe){
                c++;
                maxc=max(maxc,c); 
            }else{
                c=0;
            }
        }
        return maxc;
    }
};