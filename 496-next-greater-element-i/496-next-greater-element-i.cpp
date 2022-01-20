class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> index,output,gr;
        index=uniqueIndex(nums1,nums2);
        
        gr=nextGreater(nums2,nums2.size());
        
        for(int i=0;i<index.size();i++)
        {
            output.push_back(gr[index[i]]);
        }
        return output;
    }
    
    vector<int> uniqueIndex(vector<int> v1,vector<int> v2)
    {
        int i,j,n=v1.size(),m=v2.size();
        vector<int> output;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v1[i]==v2[j])
                    output.push_back(j);
            }
        }
        return output;
    }
    
    vector<int> nextGreater(vector<int> arr,int n){
    vector<int> v;
    stack<long long>s;
    s.push(arr[n-1]); v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false && s.top()<=arr[i])
            s.pop();
        long long ng=s.empty()?-1:s.top();
        v.push_back(ng);
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

    
};