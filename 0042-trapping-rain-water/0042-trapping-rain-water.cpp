class Solution {
public:
    
//     METHOD 1 -- NAIVE
//     int trap(vector<int>& arr) {
//          int res = 0;
//         int n = arr.size();
//         for(int i=1;i<n-1;i++)
//         {
//                 int lmax = arr[i];
//                 for(int j=0;j<i;j++)
//                 {
//                         lmax = max(lmax,arr[j]);
//                 }

//                 int rmax = arr[i];
//                 for(int j=i+1;j<n;j++)
//                 {
//                         rmax = max(rmax,arr[j]);
//                 }

//                 res += (min(lmax,rmax) - arr[i]);
//         }

//         return res;   
//     }
    
    
    
//     METHOD 2 
    int trap(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        
        int lmax[n],rmax[n];
        
        lmax[0] = arr[0];
        
        for(int i=1;i<n;i++)
        {
            lmax[i] = max(arr[i], lmax[i-1]);
        }
        
        rmax[n-1] = arr[n-1];
        
        for(int i = n-2;i>=0;i--)
        {
            rmax[i] = max(arr[i], rmax[i+1]);
        }
        
        for(int i=1;i<n;i++)
        {
            res += (min(lmax[i],rmax[i]) - arr[i]);
        }
        
        
        
        return res;   
    }
};